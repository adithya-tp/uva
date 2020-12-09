#include <bits/stdc++.h>
using namespace std;

/*
    Since we don't need to cover the edges, we can look at the rectangle
    (n - 2) x (m - 2). We essentially have a convolution operation with 
    stride = kernel_size (=3), because we want minimum overlap. 
    This is essentially side / 3, and we take a ceil of this to cover the
    fractional area.
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
    
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        n-=2;
        m-=2;
        int ans = ceil(n / 3.0) * ceil(m / 3.0);
        printf("%d\n", ans);
    }
    return 0;
}