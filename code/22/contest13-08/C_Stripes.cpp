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

#ifdef LOCAL
    #include "../debug.h"
#else
    #define deb(x...)
#endif

void _() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("../main.in",  "r", stdin);
        freopen("../main.out", "w", stdout);
        freopen("../main.err", "w", stderr);
    #endif
}

#define int long long int

void solve();

int32_t main() {
    _();
    int T;
    T = 1;
    cin >> T;
    rep (t, 0, T) { solve(); }
    return 0;
}

void solve() {
    priority_queue<int> st;
    int count = 0;
    rep (i, 0, 8) {
        rep (j, 0, 8) {
            char n;
            cin >> n;
            if (n == 'R') count++;
        }
        st.push(count);
        count = 0;
    }    
    if (st.top() == 8) cout << "R" << endl;
    else cout << "B" << endl;
}
