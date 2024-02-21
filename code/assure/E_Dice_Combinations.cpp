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
const ll MOD = 1e9 + 7;
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

vector<ll> coins = {1, 2, 3, 4, 5, 6};
vector<ll> tbl(1010101);

void solve()
{
  ll n;
  cinn(n);
  tbl[0] = 1;
  rep(i, 1, n + 1)
  {
    each(c, coins)
    {
      if (i - c >= 0)
      {
        deb(tbl[i], tbl[i - c]);
        tbl[i] += tbl[i - c];
        tbl[i] %= MOD;
      }
    }
  }
  deb(tbl);
  coutt(tbl[n]);
}
