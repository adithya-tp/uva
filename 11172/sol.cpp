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
    int t, a, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        if(a == b)
            printf("=\n");
        else if(a < b)
            printf("<\n");
        else
            printf(">\n");
    }
    return 0;
}