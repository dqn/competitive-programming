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
  int N;
  in(N);
  int ans = 0;
  int mn = INF;
  rep(i, N) {
    int pi;
    in(pi);
    if (pi <= mn) ans++;
    mn = min(mn, pi);
  }
  print(ans);
}
