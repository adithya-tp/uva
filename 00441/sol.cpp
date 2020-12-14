#include <bits/stdc++.h>
using namespace std;

/*
    Solved with Complete Search since the max value is 12, atmost
    12C6 print operations since we only need to choose 6 numbers in total.
    So atmost 924 lines get printed. And the input is already sorted sooo.
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
    int t;
    int c = 0;
    while(scanf("%d", &t), t) {
        if(c) puts("");
        c++;
        vi v(t);
        forn(i, 0, t - 1) {
            scanf("%d", &v[i]);
        }
        forn(i, 0, t - 6) {
            forn(j, i + 1, t - 5) {
                forn(k, j + 1, t - 4) {
                    forn(l, k + 1, t - 3) {
                        forn(m, l + 1, t - 2) {
                            forn(n, m + 1, t - 1) {
                                printf("%d %d %d %d %d %d\n", v[i], v[j], v[k], v[l], v[m], v[n]);
                            }
                        }
                    }
                }
            }
        }
        
    }
    return 0;
}