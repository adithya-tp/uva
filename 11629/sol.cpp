#include <bits/stdc++.h>
using namespace std;

/*
    Keep track of track of percetages using map, and check if the equality is satisfied.
    A neat trick is to multiply each of the percentages by 10 so that you don't have
    to perform inequalities with doubles.
*/

#define pb push_back
#define forn(i, l, r) for(int i = l; i <= r; i++)
#define fornr(i, r, l) for(int i = r; i >= l; i--)
#define INF 1000000000
#define x real()
#define y imag()
#define M_PI 3.14159265358979323846
typedef double T;
typedef complex<T> pt;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
inline istream& skip_endl(istream &is) { return is.ignore(numeric_limits<streamsize>::max(),'\n'); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int p, g;
    double amt;
    cin >> p >> g;
    string s, op;
    unordered_map<string, int> m;
    forn(i, 0, p - 1) {
        cin >> s;
        cin >> amt;
        m[s] = ceil(amt * 10);
    }

    forn(i, 0, g - 1) {
        int left = 0;
        while(cin >> s >> op) {
            if(op != "+") break;
            left += m[s];
        }

        left += m[s];
        int right;
        cin >> right;
        right *= 10;
        bool correct = false;
        if(op == "<") {
            correct = (left < right);
        } else if(op == "<=") {
            correct = (left <= right);
        } else if(op == ">") {
            correct = (left > right);
        } else if(op == ">=") {
            correct = (left >= right);
        } else {
            correct = (left == right);
        }
        cout << "Guess #" << i + 1 << " was ";
        if(correct)
            cout << "correct.\n";
        else
            cout << "incorrect.\n";
    }
    return 0;
}