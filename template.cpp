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
vector<int> a;

int main() {
  input(n);
  inputn(a, n);

  int ans = 0;

  print(ans);

  return 0;
}
