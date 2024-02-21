#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define pb push_back
#define endl "\n"
#define each(x, xs) for (auto &x : (xs))
#define rep(i, be, en) for (__typeof(en) i = (be) - ((be) > (en)); i != (en) - ((be) > (en)); i += 1 - 2 * ((be) > (en)))
typedef vector<int> vi;
typedef long long ll;

#ifdef LOCAL
#include "debug.h"
#define line cerr << "-------------------" << endl;
#else
#define deb(x...)
#define line
#endif

void _()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  freopen("main.err", "w", stderr);
#endif
}

void solve(int j);

int main()
{
  _();
  string T;
  T = 1;
  int j = 1;
  getline(cin, T);
  rep(t, 0, stoi(T))
  {
    solve(j);
    j++;
  }
  return 0;
}

void solve(int j)
{
  string st;
  getline(cin, st);
  int count = 0;
  stack<char> stack;
  deb(st);
  for (int i = 0; i < st.size(); i++)
  {
    if (st[i] == '[')
    {
      stack.push(st[i]);
    }
    else
    {
      if (!stack.empty())
      {
        stack.pop();
        count += 2;
      }


    }
  }
  cout << j << " " << (count == 0 ? 1 : count) << endl;
}
