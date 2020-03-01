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
vector<int> l;

int main() {
  input(n);
  inputn(l, n);

  int ans = 0;

  while (l.size() > 1) {
    sortvr(l);
    int l1 = l[l.size() - 1]; l.pop_back();
    int l2 = l[l.size() - 1]; l.pop_back();

    int len = l1 + l2;
    l.push_back(len);
    ans += len;
  }

  print(ans);

  return 0;
}
