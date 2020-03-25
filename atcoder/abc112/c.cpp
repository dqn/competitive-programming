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
#define print(...) out(__VA_ARGS__);cout<<endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void out(){} template<class T,class... U> void out(T t,U ...u){cout<<t<<" ";out(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(int, N);
  vl X(N), Y(N), H(N);
  rep(i, 0, N) {
    in(X[i], Y[i], H[i]);
  }
  rep(i, 0, 101) {
    rep(j, 0, 101) {
      ll HH = 0;
      rep(k, 0, N) {
        if (H[k] > 0) {
          HH = H[k] + abs(X[k] - i) + abs(Y[k] - j);
          break;
        }
      }
      bool ok = true;
      rep(k, 0, N) {
        ll hi = max(HH - abs(X[k] - i) - abs(Y[k] - j), 0ll);
        if (hi != H[k]) {
          ok = false;
        }
      }
      if (ok) {
        print(i, j, HH);
        return;
      }
    }
  }
}
