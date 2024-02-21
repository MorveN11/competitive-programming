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

bool vis[1000][1000];
int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
int n, m, c;

int main()
{
  _();
  int T;
  T = 1;
  // cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

void dfs(int i, int j)
{
  vis[i][j] = 1;
  rep(p, 0, 4)
  {
    int ni = i + h[p];
    int nj = j + v[p];
    if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj])
    {
      dfs(ni, nj);
    }
  }
}

int a = 0;

void solve()
{
  vector<int> arr(3);
  cin >> n >> m;
  rep(i, 0, n)
  {
    rep(j, 0, m)
    {
      char ch;
      cin >> ch;
      vis[i][j] = ch == '#';
    }
  }
  rep(i, 0, n)
  {
    rep(j, 0, m)
    {
      if (!vis[i][j])
      {
        dfs(i, j);
        c++;
      }
    }
  }
  cout << c << endl;
}
