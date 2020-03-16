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
  VAR(int, N);
  VEC(ll, A, N);
  map<ll, int> m;
  each(x, A) {
    m[x]++;
  }
  vector<ll> v;
  each(x, m) {
    if (x.second >= 4) {
      v.push_back(x.first);
      v.push_back(x.first);
    } else if (x.second >= 2) {
      v.push_back(x.first);
    }
  }
  if (v.size() < 2) {
    print(0);
    return;
  }
  sort(all(v), greater<>());
  print(v[0] * v[1]);
}
