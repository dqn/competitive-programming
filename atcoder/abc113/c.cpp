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
  VAR(ll, N, M);
  vector<vector<pll>> v(N);
  rep(i, 0, M) {
    VAR(ll, P, Y);
    v[P - 1].push_back(pll(Y, i));
  }
  vector<pll> anss(M);
  rep(i, 0, N) {
    sort(all(v[i]));
    rep(j, 0, (int)v[i].size()) {
      anss[v[i][j].second] = pll(i + 1, j + 1);
    }
  }
  each(x, anss) {
    printf("%06lld%06lld\n", x.first, x.second);
  }
}
