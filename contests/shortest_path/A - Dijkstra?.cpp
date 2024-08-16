#ifdef LOCAL
#include "/home/morven/code/competitive-programming/conf/debug.h"
#define line cerr << "-------------------" << endl;
#else
#define deb(x...)
#define line
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

template <typename... T>
void cinn(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void coutt(const T &...args) {
    __typeof(sizeof...(T)) i = 1;
    ((cout << args << (i++ != sizeof...(T) ? " " : "")), ...);
    cout << '\n';
}

template <typename T>
void couts(const T &xs) {
    for (__typeof(xs.sz()) i = 0; i < xs.sz(); i++) {
        cout << xs[i] << " \n"[i == xs.sz() - 1];
    }
}

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
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const ll INF = INT64_MAX;
const int inf = INT32_MAX;
const ld PI = acos(-1);
const lli MOD = 1e9 + 7;
const vector<int> DX{1, 0, -1, 0}, DY{0, 1, 0, -1};
ll testId = 0;

void _() {
    ios::sync_with_stdio(0);
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

void solve();

void init();

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

void init() {}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vpl> adj(n + 1);

    while (m--) {
        int s, d, w;
        cin >> s >> d >> w;

        adj[s].pb({d, w});
        adj[d].pb({s, w});
    }

    vl cost(n + 1, 1e15), prev(n + 1, -1);
    vb vis(n + 1, false);
    pqg<pl> pq;

    pq.push({0, 1});
    cost[1] = 0;

    while (!pq.empty()) {
        pl s = pq.top();
        pq.pop();

        if (vis[s.S]) continue;

        vis[s.S] = true;

        if (s.S == n) break;

        each(v, adj[s.S]) {
            int d = v.F, w = v.S;

            if (cost[d] > s.F + w) {
                prev[d] = s.S;
                cost[d] = s.F + w;

                pq.push({cost[d], d});
            }
        }
    }

    if (prev[n] == -1) {
        cout << "-1" << endl;
        return;
    }

    vector<int> path = {n};

    while (path.back() != 1) {
        path.pb(prev[path.back()]);
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " \n"[i == 0];
    }
}
