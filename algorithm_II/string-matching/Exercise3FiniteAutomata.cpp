#ifdef LOCAL
#include "/home/morven/Desktop/code/competitive-programming/conf/debug.h"
#define line cerr << "-------------------" << endl;
#else
#define deb(x...)
#define line
#endif

#include <bits/stdc++.h>
using namespace std;

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
  for (__typeof(xs.sz()) i = 0; i < xs.sz(); i++)
  {
    cout << xs[i] << " \n"[i == xs.sz() - 1];
  }
}

using ll = long long;
using ld = long double;
using lli = long long int;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

const ll INF = INT64_MAX;
const int inf = INT32_MAX;
const ld PI = acos(-1);
const lli MOD = 1e9 + 7;
const vector<int> DX{1, 0, -1, 0}, DY{0, 1, 0, -1};
ll testId = 0;

void _()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("/home/morven/Desktop/code/competitive-programming/conf/main.in", "r", stdin);
  freopen("/home/morven/Desktop/code/competitive-programming/conf/main.out", "w", stdout);
  freopen("/home/morven/Desktop/code/competitive-programming/conf/main.err", "w", stderr);
#endif
}

void solve();

void init();

void exit();

int main()
{
  _();
  init();
  ll T = 1;
  // cinn(T);
  rep(t, 0, T)
  {
    testId++;
    solve();
  }
  return 0;
}

const ll MAXN = 202020;

bool isSuffix(string pattern, int q, int k, int c)
{
  if (k == 0)
    return true;
  if (pattern[k - 1] != c)
    return false;
  rep(i, 1, k)
  {
    if (pattern[i - 1] != pattern[q - k + i])
      return false;
  }
  return true;
}

vector<vector<int>> finiteAutomata(string pattern)
{
  int N = pattern.length();
  vector<vector<int>> TF(N + 1, vector<int>(256));

  rep(q, 0, (N + 1))
  {
    rep(c, 0, 256)
    {
      int k = min(N + 1, q + 2);
      while (k > 0 && !isSuffix(pattern, q, k, c))
      {
        k--;
      }

      TF[q][c] = k;
    }
  }

  return TF;
}

void init()
{
}

void exit()
{
}

// Time Complexity: O(N^2 * 256) where N is the length of the pattern and 256 is the number of characters in the ASCII table
void solve()
{
  int q;
  string text, pattern;
  cinn(text, pattern, q);
  vector<int> values(q);
  rep(i, 0, q)
  {
    cinn(values[i]);
  }
  vector<vector<int>> TF = finiteAutomata(pattern);
  each(x, values)
  {
    int currentState = 0;
    rep(i, 0, x)
    {
      currentState = TF[currentState][text[i]];
    }
    coutt(currentState);
  }
}
