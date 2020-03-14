#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007
#define PI 3.14159265358979
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl
#define rad_to_deg(x) ((double)(x) * 180 / PI)

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

void solve() {
  double a, b, x;
  in(a, b, x);
  double ans;
  if (x < (a * a * b) / 2) {
    double depth = x / (a * b);
    ans = 90 - rad_to_deg(atan(depth / (b / 2)));
  } else {
    double depth = x / (a * a);
    ans = rad_to_deg(atan((b - depth) / (a / 2)));
  }
  printf("%.10f", ans);
}
