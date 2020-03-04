#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, s, e) for (int i = s; i < e; i++)
#define each(x, v) for (auto& x: v)
#define all(x) x.begin(), x.end()
#define input(type, ...) type __VA_ARGS__; in(__VA_ARGS__)
#define inputv(type, name, w) v<type> name(w); each(x, name) in(x)
#define inputvv(type, name, w, h) vv<type> name(h, v<type>(w)); each(x, name) each(y, x) in(y)
#define print(x) cout << x << endl
#define V(type, name, w) vector<type> name(w)
#define VV(type, name, w, h) vector<vector<type>> name(h, vector<type>(w))

void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  input(int, n);
  V(int, w, n);
  V(int, v, n);
  rep(i, n) {
    in(w[i]);
    in(v[i]);
  }
  input(int, W);

  VV(int, dp, n + 1, W + 1);

  rep(i, n) {
    rep(j, W + 1) {
      for (int k = 0; k * w[i] <= j; k++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - k * w[i]] + k * v[i]);
      }
    }
  }

  each(x, dp) each(y, x) print(y);

  print(dp[n][W]);
}
