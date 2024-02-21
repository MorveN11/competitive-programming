#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/manuel/Desktop/code/manuel-competitive/conf/debug.h"
#define line cerr << "-------------------" << endl;
#else
#define deb(x...)
#define line
#endif

template <typename... T>
void cinn(T &...args)
{
  ((cin >> args), ...);
}

template <typename... T>
void coutt(const T &...args)
{
  __typeof(sizeof...(T)) i = 1;
  ((cout << args << (i++ != sizeof...(T) ? " " : "")), ...);
  cout << '\n';
}

template <typename T>
void couts(const T &xs)
{
  __typeof(xs.size()) i = 1;
  for (auto &x : xs)
  {
    cout << x << (i++ == xs.size() ? '\n' : ' ');
  }
}

#define F first
#define S second
#define pb push_back
#define sz size
#define all(x) begin(x), end(x)
#define sortt(x) sort(all(x))
#define endl '\n'
#define int long long int
#define ll long long
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be); i < (en); i++)
#define per(i, be) for (__typeof(be) i = (be)-1; i >= 0; i--)
#define strInt(str) stoi(str)
#define chrInt(chr) (int)chr - 48
#define ensp(i, n) (i == n - 1 ? '\n' : ' ')

const int INF = INT64_MAX;
const int DX[4]{1, 0, -1, 0}, DY[4]{0, 1, 0, -1};
const long double PI = acos(-1);
const int MOD = 1e9 + 7;

void _()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("/home/manuel/Desktop/code/manuel-competitive/conf/main.in", "r", stdin);
  freopen("/home/manuel/Desktop/code/manuel-competitive/conf/main.out", "w", stdout);
  freopen("/home/manuel/Desktop/code/manuel-competitive/conf/main.err", "w", stderr);
#endif
}

void solve();

int32_t main()
{
  _();
  int T;
  T = 1;
  // cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

const int MAXN = 1001;
vector<vector<bool>> vis(MAXN);
int h, w, c;
string tx;

void dfs(int i, int j)
{
  vis[i][j] = 1;
  rep(p, 0, 4)
  {
    int y = i + DY[p];
    int x = j + DX[p];
    if (x >= 0 && x < w && y >= 0 && y < h && !vis[y][x])
    {
      dfs(y, x);
    }
  }
}

void solve()
{
  cinn(h, w);
  rep(i, 0, h)
  {
    cinn(tx);
    rep(j, 0, w)
    {
      vis[i].pb(tx[j] == '#');
    }
  }
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      if (!vis[i][j])
      {
        dfs(i, j);
        c++;
      }
    }
  }
  coutt(c);
}
