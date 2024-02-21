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
#define strInt(str) stoi(string str)
#define chrInt(chr) (int) char chr - 48
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

bool dfs(char chr1, char chr2);

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
  int n, m;
  cin >> n >> m;
  rep(i, 0, n)
  {
    char ch1, ch2;
    cin >> ch1 >> ch2;
    adj[ch1].pb(ch2);
  }

  rep(i, 0, m)
  {
    string w1, w2;
    cin >> w1 >> w2;
    deb(w1, w2);
    if (w1.size() != w2.size())
    {
      cout << "no" << endl;
      continue;
    }
    bool valid = true;
    rep(i, 0, w1.size())
    {
      if (w1[i] == w2[i])
        continue;
      bool found = false;
      vis[w1[i]] = true;
      qii.push(w1[i]);
      while (!qii.empty())
      {
        int s = qii.front();
        qii.pop();
        if (s == w2[i])
        {
          found = true;
          break;
        }
        each(n, adj[s])
        {
          if (vis[n])
            continue;
          vis[n] = true;
          qii.push(n);
        }
      }
      vector<bool> swp(maxN);
      swap(vis, swp);
      queue<int> emp;
      swap(qii, emp);
      if (!found)
      {
        valid = false;
        break;
      }
    }
    if (!valid)
    {
      cout << "no" << endl;
    }
    else
    {
      cout << "yes" << endl;
    }
  }
}
