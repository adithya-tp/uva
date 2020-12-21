#include <bits/stdc++.h>
using namespace std;

/*
    Since the input is small enough, we could iterate over all 2^20 subsets 
    in the worst case, and safe the configuration that takes up as much space as possible.

    Note: Most number of tracks is not favoured over a set with lesser tracks as long as they
    take up the same space on the tape.
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
    int n, cds, sum, max_len, config;
    bool valid;
    while(cin >> n) {
        cin >> cds;
        vi lens(cds);
        forn(i, 0, cds - 1) {
            cin >> lens[i];
        }

        max_len = INT_MIN;
        forn(i, 0, (1 << cds) - 1) {
            sum = 0, valid = true;
            forn(j, 0, cds - 1) {
                if(i & (1 << j)) {
                    if(sum + lens[j] <= n) {
                        sum += lens[j];
                    } else {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid) {
                if(sum >= max_len) {
                    max_len = sum;
                    config = i;
                }
            }
        }
        forn(j, 0, cds - 1) {
            if(config & (1 << j)) {
                cout << lens[j] << " ";
            }
        }
        cout << "sum:" << max_len << "\n";
    }
    return 0;
}