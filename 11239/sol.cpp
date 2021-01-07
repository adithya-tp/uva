#include <bits/stdc++.h>
using namespace std;

/*
    Use a map to keep track of student, organization mappings while
    removing 'student' keys who've signed up for multiple organizations.

    Use the resulting map to find the number of students who've signed up for
    different organizations and sort them according to the problem statement.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
#define INF 1000000000
#define x real()
#define y imag()
#define M_PI 3.14159265358979323846
typedef double T;
typedef complex<T> pt;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
inline istream& skip_endl(istream &is) { return is.ignore(numeric_limits<streamsize>::max(),'\n'); }

bool comp(pair<int, string> a, pair<int, string> b) {
    if(a.first > b.first) return true;
    else if(a.first == b.first) return a.second < b.second;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    string org;
    bool done = false;
    while(true) {
        unordered_map<string, string> s2o;
        set<string> exclude;
        unordered_map<string, int> o2c;
        while(getline(cin, s)) {
            if(s == "1") break;
            if(s == "0") {done = true; break;}
            string copy = s;
            transform(copy.begin(), copy.end(), copy.begin(), ::toupper);
            if(copy == s) {
                org = s;
                o2c[org] = 0;
            } else {
                if(exclude.find(s) != exclude.end())
                    continue;
                if(s2o.find(s) != s2o.end() && s2o[s] != org) {
                    s2o.erase(s);
                    exclude.insert(s);
                } else {
                    s2o[s] = org;
                }
            }
        }
        if(done)
            break;
        
        for(auto i : s2o) {
            o2c[i.second]++;
        }

        vector<pair<int, string>> pairs;
        for(auto i : o2c) {
            pairs.pb(make_pair(i.second, i.first));
        }

        sort(pairs.begin(), pairs.end(), comp);
        for(auto i : pairs) {
            cout << i.second << " " << i.first << "\n";
        }
    }

    return 0;
}