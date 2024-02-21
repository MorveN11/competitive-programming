#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define pb push_back
#define endl "\n"
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be); i < (en); i++)
#define per(i, be) for (__typeof(be) i = (be)-1; i >= 0; i--)
#define strInt(str) stoi(str)
#define chrInt(chr) (int)chr - 48
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

#ifdef LOCAL
#include "debug.h"
#define line cerr << "-------------------" << endl;
#else
#define deb(x...)
#define line
#endif

void _()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  freopen("main.err", "w", stderr);
#endif
}

vector<vector<pair<int, int>>> adj;
vector<int> dp;

void solve();

void dfs(int n);

int main()
{
  _();
  int T;
  T = 1;
  cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

int func(int v)
{
  if (dp[v] != -1)
    return dp[v];
  dp[v] = 0;
  int ans = 0;
  each(e, adj[v])
  {
    if (dp[e.f] == 0)
      continue;
    ans = max(ans, func(e.f) + e.s);
  }
  return dp[v] = ans;
}

void solve()
{
  int n, q;
  cin >> n >> q;
  deb(n, q);
  adj.assign(n, vector<pair<int, int>>());
  dp.assign(n, -1);
  rep(i, 0, q)
  {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].pb({b, w});
  }
  rep(i, 0, n)
  {
    func(i);
  }
  int pi, ans = 0;
  cin >> pi;
  ans = func(pi);
  cout << ans << " KG" << endl;
}
