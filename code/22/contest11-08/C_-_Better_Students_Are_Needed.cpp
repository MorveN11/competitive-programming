#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define size(x) x.size()
#define all(x) begin(x), end(x)
#define pb push_back
#define endl "\n"
#define each(x, xs)  for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be) - ((be) > (en)); i != (en) - ((be) > (en)); i += 1 - 2 * ((be) > (en)))
typedef vector<int> vi;

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

#define int long long int

void solve();

int32_t main() {
    _();
    int T;
    T = 1;
    // cin >> T;
    rep (t, 0, T) { solve(); }
    return 0;
}

void solve() {
    int n, m, e, b;
    cin >> n >> m >> e >> b;
    vector<pair<int, pair<int, int>>> vec(n);
    set<int> res;
    rep(i, 0, n) cin >> vec[i].f;
    rep(i, 0, n) cin >> vec[i].s.s, vec[i].s.f = -i;
    sort(all(vec));
    rep(i, 0, m) res.insert(-vec.back().s.f + 1), vec.pop_back();
    rep(i, 0, n) swap(vec[i].f, vec[i].s.s);
    sort(all(vec));
    rep(i, 0, e) res.insert(-vec.back().s.f + 1), vec.pop_back();
    rep(i, 0, n) vec[i].f += vec[i].s.s;
    sort(all(vec));
    rep(i, 0, b) res.insert(-vec.back().s.f + 1), vec.pop_back();
    each (n, res) cout << n << endl;
}
