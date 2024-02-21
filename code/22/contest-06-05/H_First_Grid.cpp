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
vector<int> dist(maxN);
queue<int> qii;

void solve();

int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};

int main()
{
  _();
  int T;
  T = 1;
  // cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

bool vis[2][2];
int matrix[2][2];
int c = 0;
int resp = 0;

void dfs(int i, int j)
{
  if (matrix[i][j] == 1)
  {
    resp++;
  }
  vis[i][j] = 1;
  rep(p, 0, 4)
  {
    int ni = i + h[p];
    int nj = j + v[p];
    if (ni >= 0 && ni < 2 && nj >= 0 && nj < 2 && !vis[ni][nj] && matrix[i][j] != 0)
    {
      dfs(ni, nj);
    }
  }
}

void solve()
{
  pii pos;
  string s1, s2;
  cin >> s1 >> s2;
  rep(i, 0, s1.size())
  {
    if (s1[i] == '#')
    {
      pos = {0, i};
      c++;
    }
    matrix[0][i] = s1[i] == '#' ? 1 : 0;
  }

  rep(i, 0, s2.size())
  {
    if (s2[i] == '#')
    {
      c++;
      pos = {1, i};
    }
    matrix[1][i] = s2[i] == '#' ? 1 : 0;
  }
  dfs(pos.f, pos.s);
  cout << (resp == c ? "Yes" : "No") << endl;
}
