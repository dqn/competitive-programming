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
