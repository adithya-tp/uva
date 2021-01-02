#include <bits/stdc++.h>
using namespace std;

/*
    Using the polar utility of the c++ <complex> library proves useful for this one.
    When the turtle receives a forward or a backward command, we push the turtle with
    a polar vector whose magnitude is the value given in that 'f' or 'b' command, and
    its angle is the angle the turtle has accumulated so far.

    For instance, for the given test case
    The turtle moves with a phase angle of 0 initially. And is pushed by a polar vector
    of magnitude of 100. It then accumulates an angle of 120 because of the left command.
    Now, when the turtle receives a "forward 100" command, it gets pushed by a polar
    vector with the same magnitude as before, but this vector pushes at angle of 120,
    the angle that the turtle has accumulated so far! 
    
    At the end, you can take the euclidean distance of the turtles coordinates from
    the origin using the abs function.

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

pt translate(pt p, double dis, double angle) {
    return p + polar(dis, angle * M_PI / 180.0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, dirs;
    double a, angle;
    string dir;
    cin >> t;
    while(t--) {
        angle = 0.0;
        pt p = polar(0.0,0.0);
        cin >> dirs;
        while(dirs--) {
            cin >> dir >> a;
            if(dir[0] == 'f') {
                p = translate(p, a, angle);
            } else if(dir[0] == 'b') {
                p = translate(p, -a, angle);
            } else if(dir[0] == 'l') {
                angle += a;
            } else {
                angle -= a;
            }
        }
        cout << int(round(abs(p))) << "\n";
    }
    return 0;
}