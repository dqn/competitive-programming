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

void solve() {
  int N, L, P;
  in(N, L, P);
  vi A(N);
  vi B(N);
  each(x, A) in(x);
  each(x, B) in(x);

  A.push_back(L);
  B.push_back(0);

  priority_queue<int> que;
  int ans = 0, pos = 0, tank = P;

  rep(i, N + 1) {
    int d = A[i] - pos;

    while (tank < d) {
      if (que.empty()) {
        print(-1);
        return;
      }

      tank += que.top();
      que.pop();
      ans++;
    }

    que.push(B[i]);
    pos = A[i];
    tank -= d;
  }

  print(ans);
}
