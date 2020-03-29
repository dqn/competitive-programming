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
  VAR(int, H, W);
  VEC(string, S, H);
  vl dx = {-1, -1, -1, 0, 0, 1, 1, 1};
  vl dy = {-1, 0, 1, -1, 1, -1, 0, 1};
  rep(i, 0, H) {
    rep(j, 0, W) {
      if (S[i][j] == '#') {
        continue;
      }
      int c = 0;
      rep(k, 0, 8) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
          continue;
        }
        if (S[ny][nx] == '#') {
          c++;
        }
      }
      S[i][j] = (char)(c + 48);
    }
  }
  rep(i, 0, H) {
    print(S[i]);
  }
}
