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
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

int n;
vvi g;
vi color;

bool dfs(int i, int c) {
  color[i] = c;
  each(x, g[i]) {
    if (color[x] == c) {
      return false;
    }
    if (color[x] == 0) {
      return dfs(x, -c);
    }
  }
  return true;
}

void solve() {
  in(n);
  g.resize(n);
  color.resize(n);

  each(x, g) {
    int m;
    in(m);
    x.resize(m);
    each(y, x) in(y);
  }

  rep(i, n) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        print("No");
        return;
      }
    }
  }

  print("Yes");
}
