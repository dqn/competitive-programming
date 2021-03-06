#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (n); i++)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

void solve() {
  int N, K;
  in(N, K);
  if (N <= K) {
    print(0);
    return;
  }
  priority_queue<ll> H;
  rep(i, N) {
    ll hi;
    in(hi);
    H.push(hi);
  }
  rep(i, K) {
    H.pop();
  }
  ll ans = 0;
  while (!H.empty()) {
    ans += H.top();
    H.pop();
  }
  print(ans);
}
