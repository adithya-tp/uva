#include <bits/stdc++.h>
using namespace std;

/*
    As long as you have enough beds and the total price 
    doesn't exceed the budget, you won't have to stay at home.
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
    int people, budget, hotels, weekends, ppp, beds;
    while(cin >> people >> budget >> hotels >> weekends) {
        bool found = false;
        int min_cost = INT_MAX;
        forn(i, 0, hotels - 1) {
            cin >> ppp;
            forn(i, 0, weekends - 1) {
                cin >> beds;
                if(beds >= people) {
                    if(people * ppp <= budget) {
                        min_cost = min(min_cost, people * ppp);
                        found = true;
                    }
                }
            }
        }
        if(found)
            cout << min_cost << "\n";
        else
            cout << "stay home\n";
    }
    return 0;
}