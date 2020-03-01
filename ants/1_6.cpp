#include <bits/stdc++.h>

#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) cin >> x[i];

using namespace std;
using ll = long long;

int n;
vector<int> a;

int main() {
  input(n);
  inputn(a, n);

  int ans = 0;

  rep(i, n) {
    range(j, i + 1, n) {
      range(k, j + 1, n) {
        int longest = max({ a[i], a[j], a[k] });
        int perimeter = a[i] + a[j] + a[k];
        if ((perimeter - longest) > longest) {
          ans = max(perimeter, ans);
        }
      }
    }
  }

  cout << ans << endl;
}
