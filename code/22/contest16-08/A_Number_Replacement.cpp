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
    int l;
    string st;
    cin >> l;
    map <int, pair<char, unordered_set<int>>> map;
    vi nms(l);
    rep (i, 0, l) {
        int n;
        cin >> n;
        map[n].s.insert(i); 
        nms[i] = n;
    }
    cin >> st;
    rep (i, 0, st.size()) map[nms[i]].f = st[i];
    string res(st);
    each (val, map) {
        each (in, val.s.s) res[in] = val.s.f;
    }
    if (st == res) cout << "YES" << endl;
    else cout << "NO" << endl;
}
