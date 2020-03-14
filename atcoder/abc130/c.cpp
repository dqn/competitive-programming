#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vector<int>>;
using pii=pair<int,int>;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
#define VAR(type,...) type __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define rrep(i,a,b) for(ll i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<< endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(ll, W, H, x, y);
  cout << (double)(W * H) / 2 << " " << (x * 2 == W && y * 2 == H);
}
