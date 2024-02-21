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

// Grafos
const int maxN = 1e5 + 1;
vector<vector<int>> adj(maxN);
vector<bool> vis(maxN, false);
vector<int> dist(maxN);
queue<int> qii;

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

map<string, int> app;
map<char, set<int>> days =
    {
        {'l', {0, 1}},
        {'m', {2, 3}},
        {'x', {4, 5}},
        {'j', {6, 7}},
        {'v', {8, 9}}};

void solve()
{
  int n;
  cin >> n;
  rep(i, 0, n)
  {
    string pl;
    cin >> pl;
    rep(j, 4, 8)
    {
      string sb = pl.substr(0, j);
      app[sb]++;
    }
  }
  int m;
  cin >> m;
  rep(i, 0, m)
  {
    string pl;
    cin >> pl;
    char d;
    cin >> d;
    if (pl.size() < 4)
    {
      cout << "IMPOSIBLE DE DETERMINAR" << endl;
      continue;
    }
    if (days[d].count(chrInt(pl[3])) != 0)
    {
      if (app.count(pl) != 0 && pl.size() < 7)
      {
        cout << "POSIBLE EXENTA: " << app[pl] << endl;
      }
      else if (app.count(pl) != 0 && pl.size() == 7)
      {
        cout << "NO MULTAR" << endl;
      }
      else
      {
        cout << "MULTAR PLACA: " << pl << endl;
      }
    }
    else
    {
      cout << "NO MULTAR" << endl;
    }
  }
  app.clear();
}
