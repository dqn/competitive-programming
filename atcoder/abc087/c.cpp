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
  VAR(int, N);
  VEC(int, A1, N);
  VEC(int, A2, N);
  vi v1(N), v2(N);
  v1[0] = A1[0];
  v2[N - 1] = A2[N - 1];
  rep(i, 1, N) {
    v1[i] = v1[i - 1] + A1[i];
    v2[N - i - 1] = v2[N - i] + A2[N - i - 1];
  }
  ll ans = 0;
  rep(i, 0, N) {
    ans = max(ans, (ll)v1[i] + v2[i]);
  }
  print(ans);
}
