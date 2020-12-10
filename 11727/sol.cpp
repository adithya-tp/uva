#include <bits/stdc++.h>
using namespace std;

/*
    Print the middle element after sorting
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
    int arr[3];
    scanf("%d", &t);
    while(t--) {
        int mid;
        forn(i, 0, 2)
            scanf("%d", arr + i);
        sort(arr, arr + 3);
        printf("Case %d: %d\n", c++, arr[1]);
    }
    return 0;
}