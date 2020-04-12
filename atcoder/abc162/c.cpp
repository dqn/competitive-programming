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

ll gcd(ll a,ll b){while(a^=b^=a^=b%=a);return b;}

void solve() {
  VAR(int, K);
  ll ans = 0;
  rep(i, 1, K+1) {
    rep(j, 1, K+1) {
      rep(k, 1, K+1) {
        ans += gcd(gcd(i, j), k);
      }
    }
  }
  print(ans);
}
