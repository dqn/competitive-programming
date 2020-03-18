using path=pair<ll,ll>;
using graph=vector<vector<path>>;

vl dijkstra(graph &g, ll s) {
  vl d(g.size(), LINF);
  priority_queue<path, vector<path>, greater<>> que;
  d[s] = 0;
  que.push(path(0, s)); // cost, index
  while (!que.empty()) {
    path p = que.top(); que.pop();
    int i = p.second;
    if (d[i] < p.first) continue;
    each(x, g[i]) {
      if (d[x.second] > d[i] + x.first) {
        d[x.second] = d[i] + x.first;
        que.push(path(d[x.second], x.second));
      }
    }
  }

  return d;
}

void solve() {
  VAR(int, N);
  graph g(N, vector<path>());

  // rep(i, 0, N - 1) {
  //   VAR(ll, ai, bi, ci);
  //   g[ai - 1].push_back(path(ci, bi - 1));
  //   g[bi - 1].push_back(path(ci, ai - 1));
  // }

  auto d = dijkstra(g, 0);
}
