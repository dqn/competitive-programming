#include <bits/stdc++.h>
using namespace std;
using ll=long long;
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
#define VEC(type,name,size) vector<type> name(size);each(x, name)in(x)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<<endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

ll power(ll a,ll n){ll ret=1;for(;n>0;n>>=1,a=a*a%MOD)if(n%2==1)ret=ret*a%MOD;return ret;}
ll comb(ll n,ll r){ll x=1,y=1;rep(i,0,r){x=x*(n-i)%MOD;y=y*(i+1)%MOD;}return x*power(y,MOD-2)%MOD;}

void solve() {
  VAR(ll, N);
  VEC(ll, A, N);
  map<ll, ll> m;
  each(x, A) {
    m[x]++;
  }

  ll sum = 0;

  each(x, m) {
    sum += (x.second * (x.second - 1)) / 2;
  }

  each(x, A) {
    print(sum - (m[x] * (m[x] - 1)) / 2 + ((m[x] - 1) * (m[x] - 2)) / 2);
  }
}
