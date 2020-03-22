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

vvi bfs(vector<vector<char>> &s, int x, int y) {
  vi dx = {0, -1, 0, 1};
  vi dy = {-1, 0, 1, 0};
  int H = s.size();
  int W = s[0].size();
  vvi d(H, vi(W, INF));
  queue<pii> que;
  que.push(pii(x, y));
  d[y][x] = 0;

  while(!que.empty()) {
    pii p = que.front(); que.pop();
    rep(i, 0, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (nx > -1 && nx < W && ny > -1 && ny < H) {
        if (s[ny][nx] != '#' && d[ny][nx] == INF) {
          que.push(pii(nx, ny));
          d[ny][nx] = d[p.second][p.first] + 1;
        }
      }
    }
  }
  return d;
}

void solve() {
  VAR(int, H, W);
  vector<vector<char>> s(H, vector<char>(W));
  int sum = 0;
  rep(i, 0, H) {
    rep(j, 0, W) {
      in(s[i][j]);
      sum += (s[i][j] == '.');
    }
  }

  int d = bfs(s, 0, 0)[H - 1][W - 1];

  if (d == INF) {
    print(-1);
  } else {
    print(sum - d - 1);
  }
}
