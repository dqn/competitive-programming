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

void solve() {
  VAR(int, N);
  VEC(int, A, N);
  map<int, int> mp;
  rep(i, 0, N) {
    mp[A[i]]++;
  }
  if (N % 2) {
    if (mp[0] != 1) {
      print(0);
      return;
    }
    mp[0]++;
  }
  each(x, mp) {
    if (x.second != 2) {
      print(0);
      return;
    }
  }
  print(power(2, (N / 2)));
}
