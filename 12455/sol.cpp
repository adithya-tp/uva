#include <bits/stdc++.h>
using namespace std;

/*
    Because of the bitwise trick to iterate through all 2^n sets
    and because n is atmost 20, a complete search solution still 
    works even though the we've got an O(n * (2^n)) algorithm.
    [for n = 20, we've got O(20 * 2^20) ~ 21M operations]
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
    int t, n, s;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &s);
        scanf("%d", &n);
        vi v(n);
        forn(i, 0, n - 1) {
            scanf("%d", &v[i]);
        }

        bool found = false;
        // The binary version of i (n bits) is essentially an instruction 
        // set as to which numbers are included and not included.
        // Also the test condition works because we want to go upto 2^n - 1
        // and 1 left shifted n times is just 1 multiplied with 2x2x... n times.
        for(int i = 0; i < (1 << n); i++) {
            int curr = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j))
                    curr += v[j];
            }
            if(curr == s) {
                printf("YES\n");
                found = true;
            }
            if(found)
                break;
        }
        if(!found) {
            printf("NO\n");
        }
    }
    return 0;
}