#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007ll
#define rep(i, n) for (int i = 0; i < (n); i++)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main(){ cin.tie(0); ios::sync_with_stdio(0); solve(); }

ll power(ll a, ll n) {
  ll ret = 1;
  for (; n > 0; n >>= 1, a = a * a % MOD) {
    if (n % 2 == 1) ret = ret * a % MOD;
  }
  return ret;
}

ll comb(ll n, ll r) {
  ll x = 1, y = 1;
  rep(i, r) {
    x = x * (n - i) % MOD;
    y = y * (i + 1) % MOD;
  }
  return x * power(y, MOD - 2) % MOD;
}

void solve()
{
  ll n, a, b;
  in(n, a, b);
  ll ans = power(2, n) - 1;
  ans = (ans - comb(n, a) + MOD) % MOD;
  ans = (ans - comb(n, b) + MOD) % MOD;
  print(ans);
}
