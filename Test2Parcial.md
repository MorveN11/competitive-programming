# Test 2 Parcial - Manuel Morales

## Q1: Why do we need to do a format proog for a greedy algorithm?

We need to do a format proof for a greedy algorithm because it is not always guaranteed that the greedy algorithm will give us the optimal solution. We need to prove that the greedy algorithm will always give us the optimal solution.

## Q2: Whe can the Rabin-Karp time complexity be worse or the same as the naive algorithm?

The Rabin-Karp time complexity can be worse or the same as the naive algorithm when the pattern is a sequence of the same character. This is because the Rabin-Karp algorithm will have to check every character in the text to see if it matches the pattern.

## Q3: Given a P, what is the highest value we can get in the prefix function and why?

The highest value we can get in the prefix function is P-1. This is because the prefix function is the length of the longest proper prefix that is also a suffix. The longest proper prefix is P-1.

## Q4: Coco's them party
### a. Identify the greedy choice.
Each guest will be given a souvenir of 1 at init. The greedy Choice get the minimum number of souvenirs to give to the guests checking the left and right neighbors of the guest. If the left or right neighbor has a higher happiness level, the current guest will get the maximum number of souvenirs of the two neighbors plus 1.

### b. Identify the optimal substructure.
The optimal substructure is satisfied because if we can find the optimal way to bring an the minimum number of souvenirs to a L1 based on happiness, the global optimal solution will contain the optimal solution for a (G - L1) and the optimal solution of an L1.

### c. Implement your solution.
```cpp
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

void init()
{
}

void exit()
{
}

int greedy(vector<int> guests)
{
  int n = guests.size();
  vector<int> souvenirs(n, 1);
  rep(i, 0, n)
  {
    if (i == 0 && guests[i] < guests[i + 1])
    {
      souvenirs[i] = souvenirs[i + 1] + 1;
    }
    else if (i == n - 1 && guests[i] < guests[i - 1])
    {
      souvenirs[i] = souvenirs[i - 1] + 1;
    }
    else if (i > 0 && i + 1 != n && (guests[i - 1] > guests[i] || guests[i + 1] > guests[i]))
    {
      souvenirs[i] = max(souvenirs[i - 1], souvenirs[i + 1]) + 1;
    }
  }
  int sum = 0;
  rep(i, 0, n)
  {
    sum += souvenirs[i];
  }
  return sum;
}

void solve()
{
  int n;
  cinn(n);
  vi guests(n);
  rep(i, 0, n)
  {
    cinn(guests[i]);
  }
  coutt(greedy(guests));
}
```

### d. What is the time complexity of your solution?

The time complexity of the solution is O(n).
