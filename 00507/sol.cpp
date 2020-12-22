#include <bits/stdc++.h>
using namespace std;

/*
    The goal is to find the range query that has the maximum sum of elements.
    It is a common DP problem, sometimes known as Max 1D range sum.

    Solved this using Kadane's algorithm, while keeping track of the 
    earliest and longest Max 1D range sum.
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

int memo[20100];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, stops, stop1, stop2, sum, route_num = 1;
    cin >> t;
    while(t--) {
        cin >> stops;
        vi niceness(stops - 1);
        forn(i, 0, stops - 2) {
            cin >> niceness[i];
        }
        int p1 = 0, stop1 = 0, stop2 = 0, sum = 0, ans = 0;
        forn(i, 1, stops - 1) {
            sum += niceness[i - 1];
            if(sum > ans || (sum == ans && (stop2 - stop1 < i - p1))) {
                ans = sum;
                stop1 = p1;
                stop2 = i;
            }
            if(sum < 0) {
                p1 = i;
                sum = 0;
            }
        }
        
        if(!ans)
            cout << "Route " << route_num++ << " has no nice parts\n";
        else
            cout << "The nicest part of route " << route_num++ << " is between stops " << stop1 + 1 << " and " << stop2 + 1 << "\n";
    }
    return 0;
}

