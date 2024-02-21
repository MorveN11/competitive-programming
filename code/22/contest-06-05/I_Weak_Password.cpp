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

void solve();

void dfs(int n);

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
  string pss;
  cin >> pss;
  int coutR = 0;
  char actCh = pss[0];
  rep(i, 1, pss.size())
  {
    if (actCh == pss[i])
    {
      coutR++;
    }
    actCh = pss[i];
  }
  if (coutR == 3)
  {
    cout << "Weak" << endl;
    return;
  }
  int coutC = 0;
  int act = pss[0] - 48;
  rep(i, 1, pss.size())
  {
    if (act == 9 && pss[i] - 48 == 0)
    {
      coutC++;
    }
    else if (pss[i] - 49 == act)
    {
      coutC++;
    }
    act = pss[i] - 48;
  }
  if (coutC == 3)
  {
    cout << "Weak" << endl;
    return;
  }
  cout << "Strong" << endl;
}
