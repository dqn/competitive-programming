#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i > (b); i--)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

void solve() {
  ll L, R;
  in(L, R);
  int ans = 2019;
  for (ll i = L; i <= min(R, L + 2019); ++i) {
    for (ll j = i + 1; j <= min(R, L + 2019); ++j) {
      ans = min(ans, (int)((i % 2019) * (j % 2019) % 2019));
    }
  }
  print(ans);
}
