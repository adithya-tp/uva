#include <bits/stdc++.h>
using namespace std;

/*
	
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.precision(10);
	cout << fixed;    
	string s, a, b;
	int t, n, q, u, v, c = 0;
	getline(cin, s);
	t = stoi(s);
	while(t--) {
		if(c)
			cout << "\n";
		c = 1;
		getline(cin, s);
		getline(cin, s);
		stringstream ss(s);
		ss >> a >> b;
		n = stoi(a);
		q = stoi(b);
		unordered_map<string, vector<string>> g;
		forn(i, 0, n - 1) {
			getline(cin, s);
			stringstream ss1(s);
			ss1 >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		forn(i, 0, q - 1) {
			unordered_map<string, int> vis;
			unordered_map<string, string> p;
			for(auto i : g) {
				p[i.first] = "#";
			}
			getline(cin, s);
			stringstream ss1(s);
			ss1 >> a >> b;
			queue<string> q;
			q.push(a);
			vis[a] = true;
			while(!q.empty()) {
				string popped = q.front();
				q.pop();
				if(popped == b)
					break;
				for(string neigh : g[popped]) {
					if(!vis[neigh]) {
						vis[neigh] = true;
						p[neigh] = popped;
						q.push(neigh);
					}
				}
			}
			string path;
			while(b != "#") {
				path = b[0] + path;
				b = p[b];
			}
			cout << path << "\n";
		}
	}
	return 0;
}
