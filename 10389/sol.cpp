#include <bits/stdc++.h>
using namespace std;

/*
    Bwoiii this took long. Parsing the given input was much harder than
    implementing Djikstra's on the parsed input.

    Alright so, for the points that are read in, the weight of each edge depends on
    the speed at which you can walk along the edge. If two edges are along the same subway
    line, the edge weight factors in the subway speed. Any other vertex combination factors in walking
    speed.

    Once this construction has been done, we may perform dijkstra's from 0 (home) and
    stop when we find the shortest distance to 1 (school).
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
#define INF 1000000000
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;

inline istream& skip_endl(istream &is) { return is.ignore(numeric_limits<streamsize>::max(),'\n'); }

int t, n;
double x[205], y[205], walk = 10.0, sub = 40.0;
char buf[2000];

double cost(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) * 60 / 1000.0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    int c = 0;
    string s;
    while(t--) {
        if(c)
            cout << "\n";
        c = 1;
        vector<vector<pair<int, double>>> g(205);
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> skip_endl;
        g[0].pb(make_pair(1, cost(0, 1) / walk));
        g[1].pb(make_pair(0, cost(0, 1) / walk));
        n = 2;
        while(getline(cin, s)) {
            if(!s.size())
                break;
            bool first = true;
            stringstream ss(s);
            while(ss >> x[n] >> y[n]) {
                if(x[n] == -1) {
                    break;
                }
                if(!first) {
                    g[n - 1].pb(make_pair(n, cost(n - 1, n) / sub));
                    g[n].pb(make_pair(n - 1, cost(n, n - 1) / sub));
                }
                if(first) first = false;
                forn(i, 0, n - 1) {
                    g[i].pb(make_pair(n, cost(n, i) / walk));
                    g[n].pb(make_pair(i, cost(n, i) / walk));
                }
                n++;
            }
        }
        
        vector<double> dis(n, INF);
        dis[0] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push(ii(0, 0));
        while(!pq.empty()) {
            auto popped = pq.top(); pq.pop();
            int w = popped.first, u = popped.second;
            if(u == 1) break;
            if(w > dis[u]) continue;
            for(auto v : g[u]) {
                if(dis[u] + v.second < dis[v.first]) {
                    dis[v.first] = dis[u] + v.second;
                    pq.push(pair<double, int>(dis[v.first], v.first));
                }
            }
        }

        cout << round(dis[1]) << "\n";
    }
    return 0;
}