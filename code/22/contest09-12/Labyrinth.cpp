#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define pb push_back
#define endl "\n"
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (int i = (be); i < (en); i++)
#define per(i, be) for (int i = (be); i >= 0; i--)
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

int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};

bool vis[1000][1000];
char moves[1000][1000], c, mv[] = {'D', 'U', 'R', 'L'};
int n, m, si, sj, ei, ej, dist[1000][1000];
queue<pii> qii;

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
  rep(i, 0, n)
  {
    rep(j, 0, m)
    {
      cin >> c;
      vis[i][j] = c == '#';
      if (c == 'A')
        si = i, sj = j;
      else if (c == 'B')
        ei = i, ej = j;
    }
  }

  vis[si][sj] = true;
  qii.push({si, sj});
  while (!qii.empty())
  {
    pii P = qii.front();
    qii.pop();
    rep(i, 0, 4)
    {
      int ni = P.f + h[i], nj = P.s + v[i];
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj])
      {
        moves[ni][nj] = mv[i];
        dist[ni][nj] = dist[P.f][P.s] + 1;
        vis[ni][nj] = true;
        qii.push({ni, nj});
      }
    }
  }

  if (!vis[ei][ej])
  {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  cout << dist[ei][ej] << endl;

  pii P = {ei, ej};
  char ans[dist[ei][ej]];
  rep(i, 0, dist[ei][ej])
  {
    char move = moves[P.f][P.s];
    ans[i] = move;
    if (move == 'D')
      P = {P.f - 1, P.s};
    else if (move == 'U')
      P = {P.f + 1, P.s};
    else if (move == 'R')
      P = {P.f, P.s - 1};
    else if (move == 'L')
      P = {P.f, P.s + 1};
  }
  per(i, dist[ei][ej] - 1) cout << ans[i];
  cout << endl;
}
