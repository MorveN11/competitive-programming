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

string trim(const string &str)
{
  size_t first = str.find_first_not_of(" \t\n\r");
  if (string::npos == first)
    return str;
  size_t last = str.find_last_not_of(" \t\n\r");
  return str.substr(first, (last - first + 1));
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

const int MAXN = 101010;
string value, token, to;
vector<string> query;
int n, q;
vector<vector<int>> adj(MAXN);
unordered_map<int, string> mp;
unordered_map<string, int> rmp;
unordered_set<string> st;
map<pair<string, string>, pair<long double, long double>> eqls;
queue<int> que;
vector<bool> vis(MAXN, false);
vector<long double> dist(MAXN, 0);
map<pair<string, pair<int, string>>, long double> dp;

void solve()
{
  readline(value);
  istringstream iss(value);
  while (getline(iss, token, ' '))
  {
    query.pb(token);
  }
  n = stoi(query[0]);
  q = stoi(query[1]);
  deb(n, q);
  query.clear();
  ll j = 0;
  rep(i, 0, n)
  {
    readline(value);
    istringstream iss(value);
    while (getline(iss, token, ' '))
    {
      token = trim(token);
      query.pb(token);
    }
    pair<long double, string> first = {stod(query[0]), query[1]};
    pair<long double, string> second = {stod(query[3]), query[4]};
    if (!st.count(first.S))
    {
      mp[j] = first.S;
      rmp[first.S] = j;
      st.insert(first.S);
      j++;
    }
    if (!st.count(second.S))
    {
      mp[j] = second.S;
      rmp[second.S] = j;
      st.insert(second.S);
      j++;
    }

    adj[rmp[first.S]].pb(rmp[second.S]);
    adj[rmp[second.S]].pb(rmp[first.S]);
    eqls[{first.S, second.S}] = {first.F, second.F};
    eqls[{second.S, first.S}] = {second.F, first.F};
    query.clear();
    deb(first, second);
  }
  rep(i, 0, q)
  {
    readline(value);
    istringstream iss(value);
    while (getline(iss, token, ' '))
    {
      token = trim(token);
      query.pb(token);
    }
    pair<long double, string> from = {stod(query[0]), query[1]};
    to = query[3];
    vis[rmp[from.S]] = true;
    dist[rmp[from.S]] = from.F;
    que.push(rmp[from.S]);
    bool found = false;

    deb(adj[rmp[from.S]], mp[9]);
    while (!que.empty())
    {
      int u = que.front();
      que.pop();
      each(v, adj[u])
      {
        if (vis[v])
        {
          continue;
        }
        deb(mp[u], mp[v]);
        pair<long double, long double> eq = eqls[{mp[u], mp[v]}];
        dist[v] = (dist[u] * eq.S) / eq.F;
        if (v == rmp[to])
        {
          found = true;
          break;
        }
        vis[v] = true;
        que.push(v);
      }
    }
    if (found)
    {
      long double number = dist[rmp[to]];
      ostringstream oss;
      if (number == static_cast<int>(number))
      {
        oss << fixed << setprecision(1) << number;
        string formattedNumber = oss.str();
        cout << formattedNumber << endl;
      }
      else
      {
        cout << scientific << setprecision(16) << number << endl;
      }
    }
    else
    {
      cout << "Impossible" << endl;
    }
    query.clear();
    vector<bool> swpvis(MAXN, false);
    vector<long double> swpdist(MAXN, 0);
    queue<int> swpQue;
    swap(vis, swpvis);
    swap(dist, swpdist);
    swap(que, swpQue);
    deb(from, to);
    line;
  }
}
