#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
#define VAR(type,...) type __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);each(x, name)in(x)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<<endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(int, N, M);
  vvi g(N, vi());
  rep(i, 0, M) {
    VAR(int, ai, bi);
    g[ai - 1].push_back(bi - 1);
  }

  // dijkstra
  priority_queue<pii, vector<pii>, greater<>> que;
  vi d(N, INF);
  d[0] = 0;
  que.push(pii(0, 0)); // index、cost

  while (!que.empty()) {
    pii p = que.top(); que.pop();
    int i = p.first;
    if (d[i] < p.second) continue;
    each(x, g[i]) {
      if (d[x] > d[i] + 1) {
        d[x] = d[i] + 1;
        que.push(pii(x, d[x]));
      }
    }
  }
  if (d[N - 1] < 3) {
    print("POSSIBLE");
  } else {
    print("IMPOSSIBLE");
  }
}
