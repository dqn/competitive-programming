#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

void solve() {
  int N, K;
  in(N, K);
  vector<int> s(N);

  rep(i, 0, N) {
    int pi;
    in(pi);
    s[i] = (i == 0 ? 0 : s[i - 1]) + pi;
  }
  int mx = 0;
  rep(i, K - 1, N) {
    mx = max(mx, s[i] - s[i - K]);
  }
  printf("%.12f\n", (mx + K) / 2.0);
}
