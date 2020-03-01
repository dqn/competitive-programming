#include <bits/stdc++.h>

#define INF 100000000
#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define sortv(x) sort(x.begin(), x.end());
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) input(x[i]);
#define print(x) cout << x << endl;

using namespace std;
using ll = long long;

int n;
vector<pair<int, int>> pv;

int main() {
  input(n);
  pv.resize(n);
  rep(i, n) {
    cin >> pv[i].second;
  }
  rep(i, n) {
    cin >> pv[i].first;
  }

  sortv(pv);

  int last_t = 0;
  int ans = 0;

  rep(i, n) {
    if (pv[i].second >= last_t) {
      last_t = pv[i].first;
      ans++;
    }
  }

  print(ans);

  return 0;
}
