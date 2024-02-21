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

// 10001
vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
vector<ll> tbl(10001);

ll getPos(int sum)
{
  each(coin, coins)
  {
    rep(i, coin, sum + 1)
    {
      tbl[i] += tbl[i - coin];
    }
  }
  return tbl[sum];
}

void solve()
{
  int n;
  cin >> n;
  tbl[0] = 1;
  int i = getPos(10000);
  while (n != 0)
  {
    cout << tbl[n] << endl;
    cin >> n;
  }
}
