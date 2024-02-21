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

// Grafos
const int maxN = 1e5 + 1;
vector<vector<int>> adj(maxN);
vector<bool> vis(maxN, false);
vector<int> dist(maxN);
queue<int> qii;
int n, m, a, b;

vector<int> ans(maxN);

void solve();

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
  vis[1] = true;
  qii.push(1);
  while (!qii.empty())
  {
    int act = qii.front();
    qii.pop();
    each(nd, adj[act])
    {
      if (vis[nd])
        continue;

      vis[nd] = true;
      ans[nd] = act;
      dist[nd] = dist[act] + 1;
      qii.push(nd);
    }
  }

  if (!vis[n])
  {
    cout << "IMPOSSIBLE" << endl;
  }

  cout << dist[n] + 1 << endl;

  int res[dist[n] + 1];
  int path = n;
  per(i, dist[n] + 1)
  {
    res[i] = path;
    path = ans[path];
  }

  rep(i, 0, dist[n] + 1)
  {
    cout << res[i] << " ";
  }
}
