#ifdef LOCAL
#include "/home/morven/Desktop/code/competitive-programming/conf/debug.h"
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
#define per(i, be) for (__typeof(be) i = (be)-1; i >= 0; i--)
#define readline(x) getline(cin, x)
#define strInt(str) stoi(str)
#define chrInt(chr) (int)chr - 48
#define ensp(i, n) (" \n"[i == n - 1])

template <typename... T>
void cinn(T &...args)
{
    ((cin >> args), ...);
}

template <typename... T>
void coutt(const T &...args)
{
    __typeof(sizeof...(T)) i = 1;
    ((cout << args << (i++ != sizeof...(T) ? " " : "")), ...);
    cout << '\n';
}

template <typename T>
void couts(const T &xs)
{
    for (__typeof(xs.sz()) i = 0; i < xs.sz(); i++)
    {
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

void _()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("/home/morven/Desktop/code/competitive-programming/conf/main.in", "r", stdin);
    freopen("/home/morven/Desktop/code/competitive-programming/conf/main.out", "w", stdout);
    freopen("/home/morven/Desktop/code/competitive-programming/conf/main.err", "w", stderr);
#endif
}

void solve();

void init();

void exit();

int main()
{
    _();
    init();
    ll T = 1;
    // cinn(T);
    rep(t, 0, T)
    {
        testId++;
        solve();
    }
    return 0;
}

const ll MAXN = 202020;

void init()
{
}

void exit()
{
}

int find(int u, vi &parent)
{
    if (u != parent[u])
    {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

void merge(int u, int v, vi &parent, vi &rank)
{
    u = find(u, parent);
    v = find(v, parent);
    if (u == v)
    {
        return;
    }
    if (rank[u] < rank[v])
    {
        swap(u, v);
    }
    parent[v] = u;
    if (rank[u] == rank[v])
    {
        rank[u]++;
    }
}

void solve()
{
    int n, m;
    cinn(n, m);
    vector<tuple<int, int, int>> edges(n + 1);
    rep(i, 0, m)
    {
        int u, v, w;
        cinn(u, v, w);
        edges[i] = {u, v, w};
    }

    sort(all(edges), [](auto &a, auto &b)
         { return get<2>(a) < get<2>(b); });

    vi parent(n + 1);
    vi rank(n + 1, 0);
    rep(i, 1, n + 1)
    {
        parent[i] = i;
    }
    int cost = 0;
    each(edge, edges)
    {
        int u, v, w;
        tie(u, v, w) = edge;
        if (find(u, parent) != find(v, parent))
        {
            merge(u, v, parent, rank);
            cost += w;
        }
    }

    coutt(cost);
}
