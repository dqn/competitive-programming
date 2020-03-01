#include <bits/stdc++.h>

#define INF 100000000
#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) input(x[i]);
#define print(x) cout << x << endl;

using namespace std;
using ll = long long;
using P = pair<int, int>;

int n, m;
int sx, sy;
int gx, gy;
vector<vector<char>> field;
vector<vector<int>> d;
vector<int> dx = { -1,  0, 1, 0 };
vector<int> dy = {  0, -1, 0, 1 };

int bfs() {
  queue<P> q;

  q.push(P(sx, sy));

  while (q.size()) {
    P p = q.front();
    q.pop();

    if (p.first == gx && p.second == gy) {
      break;
    }

    rep(i, 4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      if (field[ny][nx] == '#') continue;
      if (d[ny][nx] != INF) continue;

      d[ny][nx] = d[p.second][p.first] + 1;
      q.push(P(nx, ny));
    }
  }

  return d[gy][gx];
}

int main() {
  input(n);
  input(m);

  field.resize(n);
  d.resize(n);
  rep(i, n) {
    field[i].resize(m);
    d[i].resize(m);
    rep(j, m) {
      input(field[i][j]);
      d[i][j] = INF;

      if (field[i][j] == 'S') {
        sx = j;
        sy = i;
      } else if (field[i][j] == 'G') {
        gx = j;
        gy = i;
      }
    }
  }
  d[sy][sx] = 0;

  print(bfs());

  return 0;
}
