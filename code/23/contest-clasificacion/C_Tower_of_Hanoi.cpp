#ifdef LOCAL
#include "/home/manuel/Desktop/code/manuel-competitive/conf/debug.h"
#else
#define deb(x...)
#endif

#include <bits/stdc++.h>
using namespace std;

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

#define endl '\n'
#define int long long int
#define ll long long
#define F first
#define S second
#define pb push_back
#define sz size
#define all(x) begin(x), end(x)
#define sortt(x) sort(all(x))
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be); i < (en); i++)
#define per(i, be) for (__typeof(be) i = (be)-1; i >= 0; i--)
#define strInt(str) stoi(str)
#define chrInt(chr) (int)chr - 48
#define ensp(i, n) (i == n - 1 ? '\n' : ' ')

const int INF = INT64_MAX;
const int MOD = 1e9 + 7;
const long double PI = acos(-1);
const vector<int> DX{1, 0, -1, 0}, DY{0, 1, 0, -1};

void _()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("/home/manuel/Desktop/code/manuel-competitive/main.in", "r", stdin);
  freopen("/home/manuel/Desktop/code/manuel-competitive/main.out", "w", stdout);
  freopen("/home/manuel/Desktop/code/manuel-competitive/main.err", "w", stderr);
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
vector<pair<int, int>> vc;

void towerOfHanoi(int n, int from, int to,
                  int aux)
{
  if (n == 0)
  {
    return;
  }
  towerOfHanoi(n - 1, from, aux, to);
  vc.pb({from, to});
  towerOfHanoi(n - 1, aux, to, from);
}

void solve()
{
  int n;
  cinn(n);
  towerOfHanoi(n, 1, 3, 2);
  coutt(vc.size());
  each(p, vc)
  {
    coutt(p.F, p.S);
  }
}
