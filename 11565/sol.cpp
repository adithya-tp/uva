#include <bits/stdc++.h>
using namespace std;

/*
    The third equation gives us a way to prune our search space
    so that we can still get away with a complete search solution.
    Since C is atmost 10,000 the x, y, or z could only range from 
    -100 to +100. This gets us to around 8,000,000 [200x200x200] 
    operations per test case in the worst scenario.
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
    int t, a, b, c;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &a, &b, &c);
        bool found = false;
        for(int i = -100; i < 100; i++) {
            for(int j = -100; j < 100; j++) {
                for(int k = -100; k < 100; k++) {
                    if(i != j && j != k && k != i && (i + j + k == a) && (i * j * k == b) && (pow(i, 2) + pow(j, 2) + pow(k, 2) == c)) {
                        found = true;
                        printf("%d %d %d\n", i, j, k);
                        break;
                    }
                }
                if(found)
                    break;
            }
            if(found)
                break;
        }
        if(!found)
            printf("No solution.\n");
    }
    return 0;
}