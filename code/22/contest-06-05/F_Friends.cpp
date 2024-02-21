#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define pb push_back
#define endl "\n"
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (int i = (be); i < (en); i++)
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

void solve();

vector<bool> vis(2e5);
vector<vector<int>> adj(2e5);
int n, m;

int main()
{
  _();
  int T;
  T = 1;
  // cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

int dfs(int i, int &maxM)
{
  if (vis[i])
    return maxM;
  vis[i] = 1;
  maxM++;
  each(n, adj[i])
  {
    dfs(n, maxM);
  }
  return maxM;
}

int a = 0;

void solve()
{
  cin >> n >> m;
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  int max = 0;
  rep(i, 1, n + 1)
  {
    if (!vis[i])
    {
      int maxM = 0;
      dfs(i, maxM);
      if (max < maxM)
        max = maxM;
    }
  }
  cout << max << endl;
}
