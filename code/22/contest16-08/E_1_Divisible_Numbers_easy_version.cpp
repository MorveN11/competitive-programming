#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define pb push_back
#define endl "\n"
#define each(x, xs)  for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be) - ((be) > (en)); i != (en) - ((be) > (en)); i += 1 - 2 * ((be) > (en)))
typedef vector<int> vi;
typedef long long ll;

#ifdef LOCAL
    #include "../debug.h"
    #define line cerr << "-------------------" << endl;
#else
    #define deb(x...)
    #define line
#endif

void _() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("main.in",  "r", stdin);
        freopen("main.out", "w", stdout);
        freopen("main.err", "w", stderr);
    #endif
}

void solve();

int main() {
    _();
    int T;
    T = 1;
    cin >> T;
    rep (t, 0, T) { solve(); }
    return 0;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int mx = max(a, b);    
    bool isA = mx == a;
    if (mx&1) mx++;
    else mx += 2;
    while (true) {
        deb(mx);
        line;
        if (a*b % mx == 0) {
            int div = (int) a*b / mx;
            cout << mx << " " << div << endl;
            return;            
        } else {
            mx += 2;
            if (isA && mx > c || !isA && mx > d) {
                cout << -1 << ' ' << -1 << endl;
                return;
            }  
        }
    }
}
