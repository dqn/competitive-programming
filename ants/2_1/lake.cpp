#include <bits/stdc++.h>

#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) input(x[i]);
#define print(x) cout << x << endl;

using namespace std;
using ll = long long;

int n;
int m;
vector<vector<char>> field;

void dfs(int x, int y) {
  range(dy, -1, 2) {
    range(dx, -1, 2) {
      int nx = x + dx;
      int ny = y + dy;

      if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
        continue;
      }

      if (field[ny][nx] == 'W') {
        field[ny][nx] = '.';
        dfs(nx, ny);
      }
    }
  }
}

int main() {
  input(n);
  input(m);

  field.resize(n);
  rep(i, n) {
    field[i].resize(m);
    rep(j, m) {
      input(field[i][j]);
    }
  }

  int ans = 0;

  rep(i, n) {
    rep(j, m) {
      if (field[i][j] == 'W') {
        dfs(j, i);
        ans++;
      }
    }
  }

  print(ans);

  return 0;
}
