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
#define rrep(i,a,b) for(ll i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<< endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(int, N);
  VEC(int, v, N);
  map<int, int> even;
  map<int, int> odd;
  for (int i = 0; i < N; i += 2) {
    even[v[i]]++;
  }
  for (int i = 1; i < N; i += 2) {
    odd[v[i]]++;
  }
  vector<pii> ve;
  vector<pii> vo;
  each(x, even) {
    ve.push_back(pii(x.second, x.first));
  }
  each(x, odd) {
    vo.push_back(pii(x.second, x.first));
  }
  sort(all(ve), greater<>());
  sort(all(vo), greater<>());
  int ans = N;
  if (ve[0].second == vo[0].second) {
    if (N == 2) {
      ans = 1;
    } else {
      ans -= max(ve[0].first + vo[1].first, ve[1].first + vo[0].first);
    }
  } else {
    ans -= ve[0].first + vo[0].first;
  }
  print(ans);
}
