#include <bits/stdc++.h>

using namespace std;
using ll = long;
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

ll ans = 0;

void solve() {
  int N;
  in(N);
  vi x(N);
  vi y(N);
  vi p;
  rep(i, 0, N) {
    in(x[i], y[i]);
    p.push_back(i);
  }

  double ans = 0;
  int div = 0;

  do {
    rep(i, 1, N)
      ans += sqrt(pow(x[p[i]] - x[p[i - 1]], 2) + pow(y[p[i]] - y[p[i - 1]], 2));
    div++;
  } while(next_permutation(all(p)));

  printf("%.10f", ans / div);
}
