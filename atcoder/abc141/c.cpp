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
  int N, K, Q;
  in(N, K, Q);
  vi P(N);
  vi A(Q);
  rep(i, 0, Q) {
    int ai;
    in(ai);
    P[ai-1]++;
  }
  rep(i, 0, N) {
    if (P[i] + K > Q) {
      print("Yes");
    } else {
      print("No");
    }
  }
}
