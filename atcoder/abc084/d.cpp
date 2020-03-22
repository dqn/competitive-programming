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

bool is_prime(int x){if(x<2)return false;for(int i=2;i*i<=x;++i)if(x%i==0)return false;return true;}

void solve() {
  VAR(int, Q);
  vi l(Q), r(Q);
  rep(i, 0, Q) {
    in(l[i], r[i]);
  }

  int minl = *min_element(all(l));
  int maxr = *max_element(all(r));

  vi v(maxr + 1);

  rep(i, minl, maxr + 1) {
    v[i] = v[i - 1];
    if (is_prime(i) && is_prime((i + 1) / 2)) {
      v[i]++;
    }
  }

  rep(i, 0, Q) {
    print(v[r[i]] - v[l[i] - 1]);
  }
}
