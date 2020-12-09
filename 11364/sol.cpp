#include <bits/stdc++.h>
using namespace std;

/*
    As long as michael parks at some integer co-ordinate between l and r,
    he is going to walk a distance of 2 * (r - l), where r and l are the
    shops with the lowest and highest coordinates respectively. 

    Eg.
    1 2 4 5
    If he parks at 1, he'll get out, visit 1 through 5 and walk back to 1, dist = 2 * 4 = 8;
    If he parks at 3, he'll get out, say visit 2 and 1, walk back to 3, visit 4 and 5, 
    walk back to 3, dist = 2 + 2 + 2 + 2 = 8.

    This is the same as 2 * (r - l).
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, x;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int r = INT_MIN;
        int l = INT_MAX;
        while(n--) {
            scanf("%d", &x);
            r = max(r, x);
            l = min(l, x);
        }
        printf("%d\n", 2 * (r - l));
    }
    return 0;
}