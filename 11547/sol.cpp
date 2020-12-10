#include <bits/stdc++.h>
using namespace std;

/*
    The instructions are explicitly laid out in the question.
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
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        n = (n / 10) % 10;
        printf("%d\n", abs(n));
    }
    return 0;
}