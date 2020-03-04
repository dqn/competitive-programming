#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e18
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (n); i++)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve() {
  int p1x, p1y, p2x, p2y;
  in(p1x, p1y, p2x, p2y);
  int lenx = abs(p1x - p2x);
  int leny = abs(p1y - p2y);
  print(gcd(lenx, leny) - 1);
}
