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
int n;

void solve()
{
  cinn(n);
  while (n--)
  {
    int size;
    cinn(size);
    int rest = INT_MIN;
    int index = INT_MIN;
    vector<int> a(size);
    vector<int> b(size);
    rep(i, 0, size)
    {
      cinn(a[i]);
    }
    rep(i, 0, size)
    {
      cinn(b[i]);
    }
    bool isPossible = true;
    rep(i, 0, size)
    {
      if (a[i] == b[i])
        continue;
      int tmp = b[i] - a[i];
      if (tmp < 0)
      {
        isPossible = false;
        break;
      }
      if (rest == INT_MIN)
      {
        rest = tmp;
        index = i;
        continue;
      }
      if (rest != tmp || index != i - 1)
      {
        deb(a[i], b[i], rest, index, i);
        isPossible = false;
        break;
      }
      else
      {
        index = i;
      }
    }
    if (isPossible)
      coutt("YES");
    else
      coutt("NO");
  }
}
