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
#define VEC(type,name,size) vector<type> name(size);in(name)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<< endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(int, N, M);
  vector<bool> m(N + 1, true);
  rep(i, 0, M) {
    VAR(int, ai);
    m[ai] = false;
  }
  vector<ll> dp(N + 1);
  dp[0] = 1;
  dp[1] = 1;
  rep(i, 2, N + 1) {
    rep(j, i - 2, i) {
      if (m[j]) {
        dp[i] = (dp[i] + dp[j]) % MOD;
      }
    }
  }
  print(dp[N]);
}
