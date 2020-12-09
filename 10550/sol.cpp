#include <bits/stdc++.h>
using namespace std;

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

    int a, b, c, d;
    while(scanf("%d %d %d %d", &a, &b, &c, &d), (a || b || c || d)) {
        int deg = 0;
        if(b > a) {
            deg += 40 - (b - a);
        } else {
            deg += (a - b);
        }

        if(c > b) {
            deg += (c - b);
        } else {
            deg += 40 - (b - c);
        }

        if(d > c) {
            deg += 40 - (d - c);
        } else {
            deg += (c - d);
        }
        printf("%d\n", 720 + 360 + 9 * deg);
    }
    return 0;
}