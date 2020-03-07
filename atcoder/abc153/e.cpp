#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007
#define rep(i, a, n) for (int i = a; i < (n); i++)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

void solve() {
  int H, N;
  in(H, N);
  vi A(N), B(N);
  rep(i, 0, N) {
    in(A[i], B[i]);
  }

  vi dp(H + 1, 0);
  rep(i, 1, H + 1) {
    dp[i] = INF;
    rep(j, 0, N) {
      dp[i] = min(dp[i], B[j] + dp[max(i - A[j], 0)]);
    }
  }

  print(dp[H]);
}
