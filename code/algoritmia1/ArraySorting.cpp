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

const int MAXN = 202020;
int minArray = -1, maxArray = 0;
map<int, int> mp;

void merge(vector<int> &arr, int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  vector<int> L(n1), R(n2);

  rep(i, 0, n1)
  {
    L[i] = arr[l + i];
  }
  rep(i, 0, n2)
  {
    R[i] = arr[m + 1 + i];
  }

  int i = 0, j = 0;

  int k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      maxArray = max(maxArray, mp[R[j]]);
      minArray = minArray == -1 ? mp[R[j]] - (mp[R[j]] - k)
                                : min(minArray, mp[R[j]] - (mp[R[j]] - k));
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void sort(vector<int> &arr, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int m = l + (r - l) / 2;
  sort(arr, l, m);
  sort(arr, m + 1, r);
  merge(arr, l, m, r);
}

void sort(vector<int> &arr)
{
  sort(arr, 0, arr.size() - 1);
}

int n;
vector<int> arr;

// Time Complexity: O(nlogn)
// Space Complexity: O(n)
void solve()
{
  cinn(n);
  rep(i, 0, n)
  {
    int x;
    cin >> x;
    mp[x] = i;
    arr.pb(x);
  }
  sort(arr);
  if (minArray == 0 && maxArray == 0)
  {
    coutt("Sorted");
  }
  else
  {
    coutt(minArray, maxArray);
  }
}
