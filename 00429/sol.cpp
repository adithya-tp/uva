#include <bits/stdc++.h>
using namespace std;

/*
    Construct a graph for the list of given words by making an edge
    between words that have the same sequence of letters in all positions
    except for one.

    Then, for each query start a bfs from the first word till you encounter the
    second word.
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

bool diff_by_one(string a, string b) {
    int count = 0;
    if(a.size() != b.size())
        return false;
    forn(i, 0, a.size()) {
        if(a[i] != b[i]) {
            if(!count)
                count++;
            else
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string word, u, v;
    getline(cin, word);
    int t = stoi(word);
    getline(cin, word);
    int c = 0;
    while(t--) {
        if(c)
            cout << "\n";
        vector<string> words;
        while(getline(cin, word)) {
            if(word == "*")
                break;
            words.pb(word);
        }

        unordered_map<string, vector<string>> g;
        forn(i, 0, words.size() - 2) {
            forn(j, i + 1, words.size() - 1) {
                if(diff_by_one(words[i], words[j])) {
                    g[words[i]].pb(words[j]);
                    g[words[j]].pb(words[i]);
                }
            }
        }

        while(getline(cin, word)) {
            if(word.empty())
                break;
            stringstream ss(word);
            ss >> u;
            ss >> v;

            queue<string> q;
            q.push(u);
            int dist = 0;
            bool found = false;
            unordered_map<string, bool> vis;
            while(!q.empty() && !found) {
                int q_size = q.size();
                forn(i, 0, q_size - 1) {
                    string popped = q.front();
                    q.pop();
                    for(string neigh : g[popped]) {
                        if(neigh == v) {
                            found = true;
                            break;
                        } else {
                            if(!vis[neigh]) {
                                vis[neigh] = true;
                                q.push(neigh);
                            }
                        }
                    }
                    if(found)
                        break;
                }
                dist++;
            }
            cout << u << " " << v << " " << dist << "\n";
        }
        c++;
    }

    return 0;
}