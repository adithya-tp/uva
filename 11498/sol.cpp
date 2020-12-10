#include <bits/stdc++.h>
using namespace std;

/*
    Simply check which quadrant the given query falls into based on the giving origin point
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
    int t, a, b, x, y;
    while(scanf("%d", &t), t) {
        scanf("%d%d", &a, &b);
        while(t--) {
            scanf("%d%d", &x, &y);
            if(x == a || b == y)
                printf("divisa\n");
            else if(x > a && y > b)
                printf("NE\n");
            else if(x > a && y < b)
                printf("SE\n");
            else if(x < a && y < b)
                printf("SO\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}