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

const int MAXN = 202020;
int n;
set<int> f;
set<int> s;

void solve()
{
  cinn(n);
  if ((n * (n + 1)) / 2 & 1)
  {
    coutt("NO");
    return;
  }
  rep(i, 0, n / 2)
  {
    if (i & 1)
    {
      s.insert(i + 1);
      s.insert(n - i - (n & 1 ? 1 : 0));
    }
    else
    {
      f.insert(i + 1);
      f.insert(n - i - (n & 1 ? 1 : 0));
    }
  }
  if (n & 1)
    s.insert(n);
  coutt("YES");
  coutt(f.sz());
  couts(f);
  coutt(s.sz());
  couts(s);
}
