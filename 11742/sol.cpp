#include <bits/stdc++.h>
using namespace std;

/*
    Since the constraints are small enough, a complete search solution works.
    For each permutation, check if each of the m conditions are satisfied.
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(scanf("%d %d", &n, &m), (n || m)) {
        vi people;
        forn(i, 0, n - 1) {
            people.pb(i);
        }
        vvi cons(m, vi(3));
        forn(i, 0, m - 1) {
            scanf("%d %d %d", &cons[i][0], &cons[i][1], &cons[i][2]);
        }
        int perms = 0;
        do {
            if(m) { 
                bool nope = false;
                forn(i, 0, m - 1) {
                    int dis = distance(find(people.begin(), people.end(), cons[i][0]),  find(people.begin(), people.end(), cons[i][1]));
                    if(cons[i][2] < 0) {
                        if(abs(dis) < abs(cons[i][2])) {
                            nope = true;
                            break;
                        }
                    } else {
                        if(abs(dis) > abs(cons[i][2])) {
                            nope = true;
                            break;
                        }
                    }
                }
                if(!nope) {
                    perms++;
                }
            } else {
                perms++;
            }
        } while(next_permutation(people.begin(), people.end()));
        printf("%d\n", perms);
    }
    return 0;
}