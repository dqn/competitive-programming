#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e18
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < n; i++)
#define each(x, v) for (auto& x: v)
#define all(x) x.begin(), x.end()
#define print(x) cout << x << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

vi par, depth;

int find(int x) {
  if (par[x] == x) {
    return x;
  }
  par[x] = find(par[x]);
  return par[x];
}

void unite(int x, int y) {
  int parx = find(x);
  int pary = find(y);
  if (parx == pary) {
    return;
  }

  if (depth[x] < depth[y]) {
    par[x] = pary;
  } else {
    par[y] = parx;
    if (depth[x] == depth[y]) {
      depth[x]++;
    }
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

void solve() {
  int N, K;
  in(N, K);

  par.resize(N * 3);
  depth.resize(N * 3);

  rep(i, N * 3) {
    par[i] = i;
    depth[i] = 0;
  }

  int ans = 0;
  rep(i, K) {
    int t, x, y;
    in(t, x, y);

    if (x <= 0 || x > N || y <= 0 || y > N) {
      ans++;
      continue;
    }

    if (t == 1) {
      if (same(x, N + y) || same(x, N * 2 + y)) {
        ans++;
        continue;
      }
      unite(x, y);
    } else {
      if (same(x, y) || same(x, N * 2 + y)) {
        ans++;
        continue;
      }
    }
  }

  print(ans);
}
