#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
#define VAR(type,...) type __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);each(x, name)in(x)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<<endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(ll, N, M);
  if (abs(N - M) > 1) {
    print(0);
    return;
  }
  ll mx = max(N, M) + 1;
  vector<ll> dp(mx);
  dp[0] = 1;
  rep(i, 1, mx) {
    dp[i] = (dp[i - 1] * i) % MOD;
  }
  ll ans = (dp[N] * dp[M]) % MOD;
  if (N == M) ans = (ans * 2) % MOD;
  print(ans);
}
