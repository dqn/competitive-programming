#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
#define VAR(type,...) type __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);each(i, name)in(i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a-1);i>=(b);--i)
#define each(i,v) for(auto &i:(v))
#define all(v) (v).begin(),(v).end()
#define print(...) out(__VA_ARGS__);cout<<endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void out(){} template<class T,class... U> void out(T t,U ...u){cout<<t<<" ";out(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

ll power(ll a,ll n){ll ret=1;for(;n>0;n>>=1,a=a*a%MOD)if(n%2==1)ret=ret*a%MOD;return ret;}
ll comb(ll n,ll r){ll x=1,y=1;rep(i,0,r){x=x*(n-i)%MOD;y=y*(i+1)%MOD;}return x*power(y,MOD-2)%MOD;}

void solve() {
  VAR(ll, N, K);
  ll ans = 0;
  vl v1(N + 2);
  vl v2(N + 2);

  v1[1] = 0;
  rep(i, 2, N + 2) {
    v1[i] = v1[i - 1] + ll(i - 1);
  }

  v2[1] = N;
  rep(i, 2, N + 2) {
    v2[i] = v2[i - 1] + N - ll(i - 1);
  }

  rep(i, K, N + 2) {
    ans %= MOD;
    ans += max(v2[i] - v1[i], 0LL) + 1LL;
  }
  print(ans % MOD);
}
