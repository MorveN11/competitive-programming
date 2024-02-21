#include <bits/stdc++.h>

using namespace std;

#define endl "\n" 
#define int long long int
#define fore(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define each(a, b) for (auto (a), (b))
 
#ifdef DEBUG_LOCAL
    #include DEBUG
    #define LINE cerr << "-------------------" << endl;
#else
    #define deb(x...)
    #define LINE
#endif
 
void _() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    freopen("input.in",  "r", stdin);
    freopen("output.out", "w", stdout);
    freopen("error.err", "w", stderr);
#endif
}

 
void solve();
 
int32_t main() {
    _();
    int T;
    T = 1;
    cin >> T;
    fore (i, 0, T) { solve();}
    return 0;
}

void solve() {
    int t;
    cin >> t;
    if (t % 2 == 0) {
        fore (i, 1, t + 1) {
            if (i % 2 == 1) {
                cout << i + 1 << " ";
            } else {
                cout << i -  1 << " ";
            }
        }
    } else {
        if (t < 5) {
            cout << "-1" << endl;
            return;
        }
        fore (i, 4, t + 1) {
            cout << i << " ";
        }
        cout << 1 << " "<<  2 << " " << 3;
    }
    cout << endl;
}
