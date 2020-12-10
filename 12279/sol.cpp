#include <bits/stdc++.h>
using namespace std;

/*
    Increment answer when you see non-zero, decremenet you see zero.
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
    int t, c = 1;
    while(scanf("%d", &t), t) {
        int n, count = 0;
        while(t--) {
            scanf("%d", &n);
            if(n)
                count++;
            else
                count--;
        }
        printf("Case %d: %d\n", c, count);
        c++;
    }
    return 0;
}