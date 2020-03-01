#include <bits/stdc++.h>

#define INF 100000000
#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define sortv(x) sort(x.begin(), x.end());
#define sortvr(x) sort(x.begin(), x.end(), greater<int>());
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) input(x[i]);
#define print(x) cout << x << endl;

using namespace std;
using ll = long long;

int n;
int w;
vector<pair<int, int>> items;
vector<vector<int>> dp;

int rec(int i, int j) {
  if (dp[i][j] > -1) {
    return dp[i][j];
  }
  int res;
  if (i == n) {
    res = 0;
  } else if (items[i].first > j) {
    res = rec(i + 1, j);
  } else {
    res = max(rec(i + 1, j), rec(i + 1, j - items[i].first) + items[i].second);
  }
  dp[i][j] = res;

  return res;
}

int main() {
  input(n);
  items.resize(n);
  rep(i, n) {
    input(items[i].first);
    input(items[i].second);
  }
  input(w);

  dp.resize(n + 1);
  rep(i, n + 1) {
    dp[i].resize(w + 1);
    rep(j, w + 1) {
      dp[i][j] = -1;
    }
  }

  print(rec(0, w));

  return 0;
}
