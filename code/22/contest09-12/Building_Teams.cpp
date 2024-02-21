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
  int a;
  vector<int> a(3)
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  freopen("main.err", "w", stderr);
#endif
}

// Grafos
const int maxN = 1e5 + 1;
vector<vector<int>> adj(maxN);
vector<bool> vis(maxN, false);
vector<int> dist(maxN);
queue<int> qii;
int n, m, a, b;

vector<int> teams(maxN);

void solve();

void dfs(int n, int p = 0)
{
  each(nd, adj[n])
  {
    if (p == nd)
      continue;
    if (!vis[nd])
    {
      teams[nd] = !teams[n];
      vis[nd] = true;
      dfs(nd, n);
    }
    else
    {
      if (teams[nd] == teams[n])
      {
        cout << "IMPOSSIBLE" << endl;
        exit(0);
      }
    }
  }
}

int main()
{
  _();
  int T;
  T = 1;
  // cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

void solve()
{
  cin >> n >> m;
  rep(i, 0, m)
  {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  rep(i, 1, n + 1)
  {
    if (!vis[i])
    {
      vis[i] = true;
      dfs(i);
    }
  }
  rep(i, 1, n + 1)
  {
    cout << (!teams[i] ? 1 : 2) << " ";
  }
}
