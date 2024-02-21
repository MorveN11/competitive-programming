#include <bits/stdc++.h>

using namespace std;

#define endl "\n" 
#define int long long int
#define fore(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define each(a, b) for (auto (a), (b))
 
#ifdef DEBUG_LOCAL
    #include DEBUG
    #define LINE cerr << "-------------------" << endl;
#else
    #define deb(x...)
    #define LINE
#endif
 
void _() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
#ifdef LOCAL
    FILE* avoidW;
    freopen("input.in",  "r", stdin);
    freopen("output.out", "w", stdout);
    freopen("error.err", "w", stderr);
    static_cast<void>(avoidW);
#endif
}

 
void solve();
 
int32_t main() {
    _();
    // freopen("input.in",  "r", stdin);
    // freopen("output.out", "w", stdout);
    // freopen("error.err", "w", stderr);
    int T;
    T = 1;
    cin >> T;
    fore (i, 0, T) { solve();}
    return 0;
}

void solve() {
    string a, b;
    cin >> a >> b;
    map<int, int> map;
    fore (i, 0, a.size()) {
        if (a[i] == 'X') {
            map[0]++;
        }
    }
    fore (i, 0, b.size()) {
        if (b[i] == 'X') map[1]++;
    }
    if (map[0] == map[1]) {
        if (a[a.size() - 1] == b[b.size() - 1]) {
            cout << "=" << endl;
        } else if (a[a.size() - 1] > b[b.size() - 1]) {
            cout << "<" << endl;
        } else {
            cout << ">" << endl;
        }
    } else if (a[a.size() - 1] == b[b.size() - 1]) {
        if (a[a.size() - 1] == 'S') {
            if (map[0] > map[1]) {
                cout << "<" << endl;
            } else {
                cout << ">" << endl;
            }
        } else {
            if (map[0] > map[1]) {
                cout << ">" << endl;
            } else {
                cout << "<" << endl;
            }
        }
    } else {
        if (a[a.size() - 1] > b[b.size() - 1]) {
            cout << "<" << endl;
        } else {
            cout << ">" << endl;
        }
    }
}
