#ifdef LOCAL
#include "/home/morven/Desktop/code/manuel-competitive/conf/debug.h"
#define line cerr << "-------------------" << endl;
#else
#define deb(x...)
#define line
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
#define readline(x) getline(cin, x)

const long long int INF = INT64_MAX;
const long long int MOD = 1e9 + 7;
const long double PI = acos(-1);
const vector<int> DX{1, 0, -1, 0}, DY{0, 1, 0, -1};

void _()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("/home/morven/Desktop/code/manuel-competitive/conf/main.in", "r", stdin);
  freopen("/home/morven/Desktop/code/manuel-competitive/conf/main.out", "w", stdout);
  freopen("/home/morven/Desktop/code/manuel-competitive/conf/main.err", "w", stderr);
#endif
}

void solve();

int main()
{
  _();
  int T;
  T = 1;
  // cin >> T;
  rep(t, 0, T) { solve(); }
  return 0;
}

const int MAXN = 202020;
vector<int> vc, juc;
int q, n;

int search(int x)
{
  int l = 0, r = vc.sz() - 1, mid;
  while (l < r)
  {
    mid = (l + r) / 2;
    if (vc[mid] < x)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

/**
 * Tomando a m como el numero de jucy worms y
 * n como el numero de pilas, el tiempo de
 * complejidad de este algoritmo es O(mlogn)
 */
void solve()
{
  cinn(q);
  rep(i, 0, q)
  {
    cinn(n);
    if (i == 0)
      vc.pb(n);
    else
      vc.pb(n + vc[i - 1]);
  }
  cinn(q);
  rep(i, 0, q)
  {
    cinn(n);
    juc.pb(n);
  }
  rep(i, 0, juc.sz())
  {
    int pos = search(juc[i]);
    cout << pos + 1 << (i + 1 == juc.sz() ? "" : "\n");
  }
}
