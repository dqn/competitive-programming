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
#define print(...) out(__VA_ARGS__);cout<<endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void out(){} template<class T,class... U> void out(T t,U ...u){cout<<t<<" ";out(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(int, N, M);
  VEC(ll, A, N);
  vector<pll> p(M);
  rep(i, 0, M) {
    in(p[i].second, p[i].first);
  }
  sort(all(p), greater<>());
  sort(all(A));
  int ii = 0;
  rep(i, 0, M) {
    while (A[ii] < p[i].first && p[i].second && ii < N) {
      A[ii] = p[i].first;
      p[i].second--;
      ii++;
    }
  }
  print(accumulate(all(A), 0ll));
}
