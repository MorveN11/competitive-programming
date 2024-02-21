#ifdef LOCAL
#include "/home/morven/Desktop/code/manuel-competitive/conf/debug.h"
#define LINE cerr << "-------------------" << endl;
#else
#define deb(x...)
#define LINE
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
  for (__typeof(xs.size()) i = 0; i < xs.size(); i++)
  {
    cout << xs[i] << " \n"[i == xs.size() - 1];
  }
}

#define endl '\n'
#define F first
#define S second
#define pb push_back
#define sz size
#define all(x) begin(x), end(x)
#define sortt(x) sort(all(x))
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be); i < (en); i++)
#define per(i, be) for (__typeof(be) i = (be)-1; i >= 0; i--)
#define readline(x) getline(cin, x)
#define strInt(str) stoi(str)
#define chrInt(chr) (int)chr - 48
#define ensp(i, n) (" \n"[i == n - 1])

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using ti = tuple<int, int, int>;
using tl = tuple<long long, long long, long long>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<long long, long long>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const long long INF = INT64_MAX;
const int inf = INT32_MAX;
const long double PI = acos(-1);
const long long int MOD = 1e9 + 7;
const vector<int> DX{1, 0, -1, 0}, DY{0, 1, 0, -1};
long long testId = 0;

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

void init();

int main()
{
  _();
  init();
  long long T;
  T = 1;
  // cin >> T;
  rep(t, 0, T)
  {
    testId++;
    solve();
  }
  return 0;
}

const long long MAXN = 202020;
e void init()
{
}

void solve()
{
}
