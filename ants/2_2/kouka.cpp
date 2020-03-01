#include <bits/stdc++.h>

#define INF 100000000
#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) input(x[i]);
#define print(x) cout << x << endl;

using namespace std;
using ll = long long;

vector<int> v = { 1, 5, 10, 50, 100, 500 };
vector<int> c;
int a;

int main() {
  inputn(c, 6);
  input(a);

  int ans = 0;

  for (int i = 5; i >= 0; i--) {
    int n = min(a / v[i], c[i]);
    a -= v[i] * n;
    ans += n;
  }

  print(ans);

  return 0;
}
