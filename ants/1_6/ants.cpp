#include <bits/stdc++.h>

#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) input(x[i]);
#define print(x) cout << x << endl;

using namespace std;
using ll = long long;

int L;
int n;
vector<int> x;

int main() {
  input(L);
  input(n);
  inputn(x, n);

  int minAns = 0;
  int maxAns = 0;

  rep(i, n) {
    minAns = max({ minAns, min(x[i], (L - x[i])) });
    maxAns = max({ maxAns, x[i], (L - x[i]) });
  }

  print(minAns);
  print(maxAns);
}
