#include <bits/stdc++.h>

#define INF 100000000
#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) input(x[i]);
#define print(x) cout << x << endl;

using namespace std;
using ll = long long;

int n;
string s, t;

int main() {
  input(n);
  input(s);

  t = "";
  int l = 0;
  int r = n - 1;

  while (r >= l) {
    char lc = s.at(l);
    char rc = s.at(r);

    if (lc < rc) {
      t += lc;
      l++;
    } else {
      t += rc;
      r--;
    }
  }

  print(t);

  return 0;
}
