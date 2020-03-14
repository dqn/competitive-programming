#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;

#define INF 1e9
#define MOD 1000000007
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i > (b); i--)
#define each(x, v) for (auto& x: (v))
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl

void solve();
void in(){} template<class T, class... U> void in(T &t, U &...u){ cin >> t; in(u...); }
int main() { cin.tie(0); ios::sync_with_stdio(0); solve(); }

void solve() {
  string S;
  in(S);
  vi ans(S.length());
  int cnt = 0;
  rep(i, 0, (int)S.length() - 1) {
    if (S[i] == 'L') {
      cnt = 0;
      continue;
    }
    cnt++;
    if (S[i + 1] == 'L') {
      ans[i] += ((cnt - 1) / 2) + 1;
      ans[i + 1] += (cnt / 2);
    }
  }
  cnt = 0;
  rrep(i, (int)S.length() - 1, 0) {
    if (S[i] == 'R') {
      cnt = 0;
      continue;
    }
    cnt++;
    if (S[i - 1] == 'R') {
      ans[i] += ((cnt - 1) / 2) + 1;
      ans[i - 1] += (cnt / 2);
    }
  }

  each(x, ans) {
    cout << x << ' ';
  }
}
