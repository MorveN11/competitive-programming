#ifdef LOCAL
#include "/home/manuel/Desktop/code/manuel-competitive/conf/debug.h"
#else
#define deb(x...)
#endif

#include <bits/stdc++.h>
using namespace std;

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
  __typeof(xs.size()) i = 1;
  for (auto &x : xs)
  {
    cout << x << (i++ == xs.size() ? '\n' : ' ');
  }
}

#define endl '\n'
#define int long long int
#define ll long long
#define F first
#define S second
#define pb push_back
#define sz size
#define all(x) begin(x), end(x)
#define sortt(x) sort(all(x))
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be); i < (en); i++)
#define per(i, be) for (__typeof(be) i = (be)-1; i >= 0; i--)
#define strInt(str) stoi(str)
#define chrInt(chr) (int)chr - 48
#define ensp(i, n) (i == n - 1 ? '\n' : ' ')

const int INF = INT64_MAX;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1);
const vector<ll> DX{1, 0}, DY{0, 1};

void _()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("/home/manuel/Desktop/code/manuel-competitive/main.in", "r", stdin);
  freopen("/home/manuel/Desktop/code/manuel-competitive/main.out", "w", stdout);
  freopen("/home/manuel/Desktop/code/manuel-competitive/main.err", "w", stderr);
#endif
}

void solve();

int32_t main()
{
  _();
  int T;
  T = 1;
  // cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

const int MAXN = 1001;
vector<vector<pair<bool, bool>>> adj;
ll n, cnt = 0;
char c;

bool dfs(pair<ll, ll> &in, pair<ll, ll> &en)
{
  if (adj[in.F][in.S].F && adj[in.F][in.S].S)
  {
    cnt++;
    cnt %= MOD;
    return true;
  }
  if (adj[in.F][in.S].F && !adj[in.F][in.S].S)
  {
    return false;
  }
  if (in.F == en.F && in.S == en.S)
  {
    cnt++;
    cnt %= MOD;
    return true;
  }
  adj[in.F][in.S].F = true;
  rep(i, 0, 2)
  {
    pair<ll, ll> nin = {in.F + DX[i], in.S + DY[i]};
    if (nin.F < n && nin.S < n)
    {
      if (dfs(nin, en))
        adj[in.F][in.S].S = true;
    }
  }
  return adj[in.F][in.S].S;
}

void solve()
{
  cinn(n);
  adj.assign(n, vector<pair<bool, bool>>(n, {false, false}));
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      cinn(c);
      adj[i][j].F = c == '*';
    }
  }
  pair<ll, ll> in = {0, 0};
  pair<ll, ll> en = {n - 1, n - 1};
  dfs(in, en);
  coutt(cnt);
}
