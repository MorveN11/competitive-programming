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

vector<vector<bool>> adj;
int h, w;
char c;
pair<int, int> init;
set<long> results;

void solve()
{
  cinn(w, h);
  while (w != 0 && h != 0)
  {
    adj.assign(h, vector<bool>(w, false));
    rep(i, 0, h)
    {
      rep(j, 0, w)
      {
        cinn(c);
        if (c == 'X')
        {
          init = {i, j};
          adj[i][j] = false;
        }
        adj[i][j] = c == '#';
      }
    }
    if (init.F == h - 1 || init.S == w - 1 || init.F == 0 || init.S == 0)
    {
      coutt(0);
      cinn(w, h);
      continue;
    }
    map<pair<int, int>, int> dst;
    queue<pair<int, int>> q;
    dst[init] = 0;
    adj[init.F][init.S] = true;
    q.push(init);
    while (!q.empty())
    {
      pair<int, int> s = q.front();
      q.pop();
      rep(i, 0, 4)
      {
        pair<int, int> nin = {s.F + DX[i], s.S + DY[i]};
        if (nin.F < h && nin.S < w && nin.F >= 0 && nin.S >= 0)
        {
          if (adj[nin.F][nin.S])

            continue;
          adj[nin.F][nin.S] = true;
          dst[nin] = dst[s] + 1;
          if (nin.F == h - 1 || nin.S == w - 1 || nin.F == 0 || nin.S == 0)
          {
            results.insert(dst[nin]);
          }
          q.push(nin);
        }
      }
    }
    if (results.size() == 0)
      coutt(-1);
    else
    {
      each(i, results)
      {
        coutt(i);
        break;
      }
    }
    results.clear();
    cinn(w, h);
  }
}
