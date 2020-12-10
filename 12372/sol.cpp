#include <bits/stdc++.h>
using namespace std;

/*
    If any of the dimensions are bigger than 20 then it can't fit.
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
    int t, a, b, c;
    int cs = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &c);
        printf("Case %d: ", cs);
        cs++;
        if(a > 20 || b > 20 || c > 20)
            printf("bad\n");
        else
            printf("good\n");
    }
    return 0;
}