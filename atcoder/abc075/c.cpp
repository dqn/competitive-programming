#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
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

using path=pair<ll,ll>;
using graph=vector<vector<path>>;

bool dijkstra(graph &g, ll s, int a, int b) {
  vl d(g.size(), LINF);
  priority_queue<path, vector<path>, greater<>> que;
  d[s] = 0;
  que.push(path(0, s)); // cost, index
  while (!que.empty()) {
    path p = que.top(); que.pop();
    int i = p.second;
    if (d[i] < p.first) continue;
    each(x, g[i]) {
      if ((x.second == a && i == b) || (x.second == b && i == a)) {
        continue;
      }
      if (d[x.second] > d[i] + x.first) {
        d[x.second] = d[i] + x.first;
        que.push(path(d[x.second], x.second));
      }
    }
  }
  each(x, d) {
    if (x == LINF) {
      return true;
    }
  }

  return false;
}

void solve() {
  VAR(int, N, M);
  graph g(N, vector<path>());
  vector<path> v(M);

  rep(i, 0, M) {
    VAR(ll, ai, bi);
    g[ai - 1].push_back(path(1, bi - 1));
    g[bi - 1].push_back(path(1, ai - 1));
    v[i] = path(ai - 1, bi - 1);
  }

  int ans = 0;
  rep(i, 0, M) {
    if (dijkstra(g, 0, v[i].first, v[i].second)) {
      ans++;
    }
  }
  print(ans);
}
