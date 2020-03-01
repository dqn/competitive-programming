#include <bits/stdc++.h>

#define range(i, begin, end) for (int i = begin; i < end; i++)
#define rep(i, n) range(i, 0, n)
#define input(x) cin >> x;
#define inputn(x, n) x.resize(n); rep(i, n) input(x[i]);
#define print(x) cout << x << endl;

using namespace std;
using ll = long long;

int n;
int k;
vector<int> a;

bool dfs(int depth, int sum) {
  if (depth == n) return sum == k;
  if (dfs(depth + 1, sum) || dfs(depth + 1, sum + a[depth])) return true;

  return false;
}

int main() {
  input(n);
  inputn(a, n);
  input(k);

  print((dfs(0, 0) ? "Yes" : "No"));

  return 0;
}
