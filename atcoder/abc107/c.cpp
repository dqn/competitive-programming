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

void solve() {
  VAR(int, N, K);
  VEC(ll, X, N);

  vl l, r;
  rep(i, 0, N) {
    if (X[i] < 0) {
      l.push_back(X[i] * -1);
    } else {
      r.push_back(X[i]);
    }
  }

  reverse(all(l));

  ll ans = LINF;
  rep(i, 0, K + 1) {
    int ln = i;
    int rn = K - i;
    if (ln > (int)l.size() || rn > (int)r.size()) {
      continue;
    }
    ll ld = ln ? l[ln - 1] : 0;
    ll rd = rn ? r[rn - 1] : 0;
    ll d = ld + rd + min(ld, rd);
    ans = min(ans, d);
  }

  print(ans);
}
