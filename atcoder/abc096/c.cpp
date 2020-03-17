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
  VAR(int, H, W);
  vector<vector<char>> s(H, vector<char>(W));
  each(y, s) {
    each(x, y) {
      in(x);
    }
  }
  vi dx = {0, -1, 0, 1};
  vi dy = {-1, 0, 1, 0};
  rep(i, 0, H) {
    rep(j, 0, W) {
      if (s[i][j] == '.') {
        continue;
      }
      int cnt = 0;
      rep(k, 0, 4) {
        int nx = j + dx[k];
        int ny = i + dy[k];
        if (nx < 0 || nx >= W || ny < 0 || ny >= H) {
          continue;
        }
        if (s[ny][nx] == '#') {
          cnt++;
        }
      }
      if (cnt == 0) {
        print("No");
        return;
      }
    }
  }
  print("Yes");
}
