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
  int N, M;
  in(N, M);
  vector<bool> ac(N);
  vector<int> pen(N);
  rep(i, 0, M) {
    int pi;
    string si;
    in(pi, si);
    pi--;
    if (ac[pi]) continue;
    if (si == "AC") {
      ac[pi] = true;
    } else {
      pen[pi]++;
    }
  }
  int acn = 0, penn = 0;
  rep(i, 0, N) {
    if (ac[i]) {
      acn++;
      penn += pen[i];
    }
  }
  cout << acn << ' ' << penn << endl;
}
