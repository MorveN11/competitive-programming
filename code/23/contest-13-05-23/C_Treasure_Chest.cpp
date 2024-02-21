#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define pb push_back
#define endl '\n'
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
  // cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

void solve()
{
  int n;
  cin >> n;
  int indexOpen = -1;
  int indexClose = -1;
  string txt;
  cin >> txt;
  rep(i, 0, n)
  {
    if (txt[i] == '*' && indexOpen != -1 && indexClose == -1 && i > indexOpen)
    {
      cout << "in" << endl;
      return;
    }
    if (txt[i] == '*')
    {
      deb(indexOpen, txt[i], indexClose);
      cout << "out" << endl;
      return;
    }
    if (txt[i] == '|' && indexOpen == -1)
    {
      indexOpen = i;
    }
    else if (txt[i] == '|' && indexOpen != -1)
    {
      indexClose = i;
    }
  }
}