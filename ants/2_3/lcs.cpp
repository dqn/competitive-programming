#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define each(x, v) for (auto& x: v)
#define all(x) x.begin(), x.end()
#define input(type, ...) type __VA_ARGS__; in(__VA_ARGS__)
#define inputv(type, name, w) v<type> name(w); each(x, name) in(x)
#define inputvv(type, name, w, h) vv<type> name(h, v<type>(w)); each(x, name) each(y, x) in(y)
#define print(x) cout << x << endl
#define v(type, name, w) vector<type> name(w)
#define vv(type, name, w, h) vector<vector<type>> name(h, vector<type>(w))

void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  input(int, n, m);
  input(string, s, t);

  vv(int, dp, n + 1, m + 1);

  rep(i, n) {
    rep(j, m) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  print(dp[n][m]);
}
