#include <bits/stdc++.h>
using namespace std;

/*
    Print the absolute difference between the numbers in each line
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
    long long int a, b;
    while(cin >> a >> b) {
        cout << abs(b - a) << "\n";
    }
    return 0;
}