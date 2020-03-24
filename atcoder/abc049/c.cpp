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

void solve() {
  VAR(string, S);
  int i = S.length() - 1;
  while (i > 0) {
    string s5 = S.substr(max(i - 4, 0), 5);
    string s6 = S.substr(max(i - 5, 0), 6);
    string s7 = S.substr(max(i - 6, 0), 7);
    if (s6 == "eraser") {
      i -= 6;
    } else if (s5 == "erase") {
      i -= 5;
    } else if (s7 == "dreamer") {
      i -= 7;
    } else if (s5 == "dream") {
      i -= 5;
    } else {
      print("NO");
      return;
    }
  }
  print("YES");
}
