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

int tst = 1;

int main()
{
  _();
  string a;
  a = 1;
  getline(cin, a);
  int T = stoi(a);
  rep(t, 0, T) { solve(); }
  return 0;
}

void solve()
{
  int count = 0;
  int ops = 0;
  string txt;
  getline(cin, txt);
  rep(i, 0, txt.size())
  {
    if (txt[i] == '[')
    {
      ops++;
    }
    else
    {
      if (ops > 0)
      {
        ops--;
        count++;
      }
    }
  }
  if (count == 0)
    count = 1;
  else
    count *= 2;
  cout << tst++ << " " << count << endl;
}
