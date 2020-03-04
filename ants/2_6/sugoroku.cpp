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

int extgcd(int a, int b, int &x, int &y) {
  int d = a;
  if (b == 0) {
    x = 1;
    y = 0;
  } else {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return d;
}

void solve() {
  int a, b, x, y;
  in(a, b);

  int d = extgcd(a, b, x, y);
  if (d != 1) {
    print(-1);
    return;
  }

  string ans = "";
  ans += to_string(max(x, 0)) + " ";
  ans += to_string(max(y, 0)) + " ";
  ans += to_string(abs(min(x, 0))) + " ";
  ans += to_string(abs(min(y, 0)));
  print(ans);
}
