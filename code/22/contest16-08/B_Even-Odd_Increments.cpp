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
    #include "debug.h"
#else
    #define deb(x...)
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
    int l, q, odds = 0, evens = 0;
    ll sum = 0;
    cin >> l >> q;
    rep (i, 0, l) {
        int n;
        cin >> n;
        if (n&1) odds++;
        else evens++;
        sum += n;
    }    
    rep (i, 0, q) {
        int odd, amn;
        cin >> odd >> amn;
        if (odd&1) {
            sum += amn*odds;
            if (amn&1) evens += odds, odds = 0;
        } else {
            sum += amn*evens;
            if (amn&1) odds += evens, evens = 0;
        }
        cout << sum << endl;
    }
}
