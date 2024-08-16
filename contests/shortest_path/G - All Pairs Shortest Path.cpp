#ifdef LOCAL
#include "/home/morven/code/competitive-programming/conf/debug.h"
#else
#define deb(x...)
#endif

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define F first
#define S second
#define pb push_back
#define sz size
#define all(x) begin(x), end(x)
#define sortt(x) sort(all(x))
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be); i < (en); i++)
#define per(i, be) for (__typeof(be) i = (be) - 1; i >= 0; i--)
#define readline(x) getline(cin, x)
#define strInt(str) stoi(str)
#define chrInt(chr) (int)chr - 48
#define ensp(i, n) (" \n"[i == n - 1])
#define spne(i) (" \n"[i == 0])

using ll = long long;
using ld = long double;
using lli = long long int;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;

const ll INF = LONG_MAX;
const int inf = int(1e9);
const ld PI = acos(-1);
const lli MOD = 1e9 + 7;
const vector<int> DX{1, 0, -1, 0}, DY{0, 1, 0, -1};
ll testId = 0;

void _() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("/home/morven/code/competitive-programming/conf/main.in", "r",
            stdin);
    freopen("/home/morven/code/competitive-programming/conf/main.out", "w",
            stdout);
    freopen("/home/morven/code/competitive-programming/conf/main.err", "w",
            stderr);
#endif
}

void init();

void solve();

int main() {
    _();
    init();
    ll T = 1;

    // cinn(T);
    rep(t, 0, T) {
        testId++;
        solve();
    }

    return 0;
}

const ll MAXN = 202020;

void init() {}

vvi shortest_path(int n, int m, int q) {
    vvi dist(n, vi(n, inf));

    rep(i, 0, n) dist[i][i] = 0;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
        if (dist[i][k] != inf && dist[k][j] != inf) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    rep(k, 0, n) {
        if (dist[k][k] >= 0) continue;

        rep(i, 0, n) rep(j, 0, n) {
            if (dist[i][k] != inf && dist[k][j] != inf) {
                dist[i][j] = -inf;
            }
        }
    }

    return dist;
}

void solve() {
    int n, m, q;

    cin >> n >> m >> q;

    while (n != 0 && m != 0 && q != 0) {
        vvi dist = shortest_path(n, m, q);

        while (q--) {
            int u, v;
            cin >> u >> v;

            if (dist[u][v] == inf) {
                cout << "Impossible" << endl;
            } else if (dist[u][v] == -inf) {
                cout << "-Infinity" << endl;
            } else {
                cout << dist[u][v] << endl;
            }
        }

        cout << endl;

        cin >> n >> m >> q;
    }
}
