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
#define rrep(i,a,b) for(ll i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<< endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(int, N);
  VEC(int, h, N);
  int ans = 0;
  int cnt = INF;
  while (cnt > 0) {
    cnt = 0;
    bool f = true;
    rep(i, 0, N) {
      if (h[i] > 0) {
        h[i]--;
        if (f) {
          cnt++;
          f = false;
        }
      } else {
        f = true;
      }
    }
    ans += cnt;
  }
  print(ans);
}
