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
  int N;
  in(N);
  vector<ll> A(N + 1);
  vector<ll> B(N);
  each(x, A) in(x);
  each(x, B) in(x);
  ll ans = 0;
  rrep(i, N - 1, -1) {
    ll t1 = min(A[i + 1], B[i]);
    ll t2 = min(A[i], B[i] - t1);
    A[i] -= t2;
    ans += t1 + t2;
  }
  print(ans);
}
