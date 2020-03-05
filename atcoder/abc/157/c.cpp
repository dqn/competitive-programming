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

void solve() {
  int N, M;
  in(N, M);
  vector<char> s(N);

  if (N == 1 && M == 0) {
    print(0);
    return;
  }

  rep(i, M) {
    int si;
    char ci;
    in(si, ci);

    if (si == 1 && N != 1 && ci == '0') {
      print(-1);
      return;
    }

    if (s[si - 1] != 0) {
      if (s[si - 1] != ci) {
        print(-1);
        return;
      }
    }

    s[si - 1] = ci;
  }

  rep(i, N) {
    char pad = i == 0 ? '1' : '0';
    cout << (s[i] == 0 ? pad : s[i]);
  }
  cout << endl;
}
