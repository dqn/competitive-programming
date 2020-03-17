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
  vvi c(3, vi(3));
  rep(i, 0, 3) {
    rep(j, 0, 3) {
      in(c[i][j]);
    }
  }
  rep(i, 0, 3) {
    set<int> a, b;
    rep(j, 0, 3) {
      a.insert(c[i][j] - c[(i + 2) % 3][j]);
      b.insert(c[j][i] - c[j][(i + 2) % 3]);
    }
    if (a.size() != 1 || b.size() != 1) {
      print("No");
      return;
    }
  }
  print("Yes");
}