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

int c[10][10];

void solve() {
  int N;
  in(N);
  rep(i, 1, N + 1) {
    int a = i % 10;
    int b = i;
    while (b >= 10) b /= 10;
    c[a][b]++;
  }
  int ans = 0;
  rep(i, 1, 10) {
    rep(j, 1, 10) {
      ans += c[i][j] * c[j][i];
    }
  }
  print(ans);
}
