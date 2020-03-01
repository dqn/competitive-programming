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

int n, r;
vector<int> x;

int main() {
  input(n);
  input(r);
  inputn(x, n);

  sortv(x);

  int i = 0;
  int l = x[i];
  int ans = 0;

  while (i < n) {
    l += r * 2;

    while (i < n && x[i] < l) i++;

    l = x[i];
    ans++;
  }

  print(ans);

  return 0;
}
