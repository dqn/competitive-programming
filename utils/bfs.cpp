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
