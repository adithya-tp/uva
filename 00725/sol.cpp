#include <bits/stdc++.h>
using namespace std;

/*
    Can be solved with Complete Search if we prune our search area. 
    We can do this by noticing that the second number (fghij) has to 
    start with 0, and can only go upto 98765 / n.

    It can only go upto that value because fghij has to be 1 / N th 
    of abcde. Since abcde can't be any bigger than 98765, it doesn't
    make sense to search for an fghij bigger than 1 / N of 98765.

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
    int n;
    int c = 0;
    while(scanf("%d", &n), n) {
        if(c) puts("");
        c++;
        bool found = false;
        for(int i = 1234; i <= 98765 / n; i++) {
            int tmp, used = (i < 10000);
            /*
                The following two while loops are a bitwise trick to check for all unique
                digits among the two numbers abcde = i * N, and fghij = i. The or position
                essentially fills up with 1 in the 'digits' position and if the two numbers
                together share 10 unique digits then the variable used holds the value 1111111111.
            */
            tmp = i * n;
            while(tmp) {
                used |= (1 << tmp % 10);
                tmp /= 10;
            }
            tmp = i;
            while(tmp) {
                used |= (1 << tmp % 10);
                tmp /=10;
            }
            if(used == (1 << 10) - 1) {
                found = true;
                printf("%d / %05d = %d\n", i * n, i, n);
            }
        }
        if(!found)
            printf("There are no solutions for %d.\n", n);
        
    }
    return 0;
}