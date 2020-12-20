#include <bits/stdc++.h>
using namespace std;

/*
    Keep finding the sum of the digits till you get a sum less than 10.
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
    long long int num, sum;
    while(cin >> num, num) {
        if(num < 10) {
            cout << num << "\n";
            continue;
        }
        do {
            sum = 0;
            while(num) {
                sum += (num % 10);
                num /= 10;
            }
            num = sum;
        } while(sum > 9);
        cout << sum << "\n";
    }
    return 0;
}