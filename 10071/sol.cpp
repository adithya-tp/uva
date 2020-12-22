#include <bits/stdc++.h>
using namespace std;

/*
    We use the Newton's equations for motion to arrive at the final answer of 2 * v * t.
    v = u + at => u = (v - at)
    S = ut + (1/2)*at^2 = (v - at) * (2t) + (1/2) * a(2t)^2 (substitute t = 2t, since we need the answer after 2t)
                        = 2vt - 2at^2 + 2at^2
                        = 2vt
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
    int a, b;
    while(cin >> a >> b) {
        cout << 2 * a * b << "\n";
    }
    return 0;
}