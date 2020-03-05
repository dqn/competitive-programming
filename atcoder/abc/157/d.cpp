#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (n); i++)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

struct union_find {
  vi par, rank;
  inline union_find(int n) { par.assign(n, -1); rank.resize(n); }
  inline int find(int x) { return (par[x] < 0) ? x : par[x] = find(par[x]); }
  inline bool same(int x, int y) { return find(x) == find(y); }
  inline int size(int x) { return -par[find(x)]; }
  inline void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    else if (rank[x] == rank[y]) rank[x]++;
    par[x] += par[y];
    par[y] = x;
  }
};

void solve() {
  int N, M, K;
  in(N, M, K);
  union_find uf(N);
  vi ans(N);

  rep(i, M) {
    int a, b;
    in(a, b);
    a--; b--;
    uf.unite(a, b);
    ans[a]--;
    ans[b]--;
  }
  rep(i, K) {
    int c, d;
    in(c, d);
    c--; d--;
    if (uf.same(c, d)) {
      ans[c]--;
      ans[d]--;
    }
  }

  rep(i, N) {
    ans[i] += uf.size(i) - 1;
    cout << (i == 0 ? "" : " ") << ans[i];
  }

  cout << endl;
}
