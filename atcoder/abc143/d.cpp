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
  int N;
  in(N);
  vi L(N);
  each(x, L) in(x);

  sort(all(L));

  ll ans = 0;
  rep(i, 0, N)
    rep(j, i + 1, N)
      ans += lower_bound(all(L),L[i] + L[j]) - L.begin() - j - 1;

  print(ans);
}
