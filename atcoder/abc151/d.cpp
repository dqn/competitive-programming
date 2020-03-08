#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

int H, W;
char S[20][20];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int x, int y) {
  queue<pii> que;
  vvi d(H, vi(W, INF));
  que.push(pii(x, y));
  int mx = 0;
  d[y][x] = 0;

  while(!que.empty()) {
    pii p = que.front(); que.pop();
    rep(i, 0, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if (nx > -1 && nx < W && ny > -1 && ny < H) {
        if (S[ny][nx] != '#' && d[ny][nx] == INF) {
          que.push(pii(nx, ny));
          d[ny][nx] = d[p.second][p.first] + 1;
          mx = d[ny][nx];
        }
      }
    }
  }
  return mx;
}

void solve() {
  in(H, W);
  rep(i, 0, H) {
    rep(j, 0, W) {
      in(S[i][j]);
    }
  }
  int mx = 0;
  rep(i, 0, H) {
    rep(j, 0, W) {
      if (S[i][j] != '#') {
        mx = max(mx, bfs(j, i));
      }
    }
  }
  print(mx);
}
