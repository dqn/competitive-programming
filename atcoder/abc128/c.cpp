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
#define VEC(type,name,size) vector<type> name(size);in(name)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<< endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

int N, M;
int s[10][10];
int p[10];
int ans = 0;
int m[10];

void dfs(int depth) {
  if (depth == N) {
    rep(i, 0, M) {
      int cnt = 0;
      rep(j, 0, M) {
        if (s[i][j] == 0) break;
        cnt += m[s[i][j] - 1];
      }
      if (cnt % 2 != p[i]) return;
    }
    ans++;
    return;
  }
  m[depth] = 0;
  dfs(depth + 1);
  m[depth] = 1;
  dfs(depth + 1);
}

void solve() {
  in(N, M);
  rep(i, 0, M) {
    VAR(int, k);
    rep(j, 0, k) in(s[i][j]);
  }
  rep(i, 0, M) in(p[i]);

  dfs(0);
  print(ans);
}
