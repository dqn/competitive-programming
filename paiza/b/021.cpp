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
  VAR(int, N);
  VEC(string, a, N);

  each(x, a) {
    int s = x.length();
    string l2 = x.substr(s - 2, 2);
    string l1 = x.substr(s - 1, 1);
    char c = x[s - 2];
    if (
      l1 == "s"
      || l2 == "sh"
      || l2 == "ch"
      || l1 == "o"
      || l1 == "x"
    ) {
      print(x + "es");
    } else if (l1 == "f") {
      print(x.substr(0, s - 1) + "ves");
    } else if (l2 == "fe") {
      print(x.substr(0, s - 2) + "ves");
    } else if (l1 == "y" && (
      c != 'a'
      && c != 'i'
      && c != 'u'
      && c != 'e'
      && c != 'o'
    )) {
      print(x.substr(0, s - 1) + "ies");
    } else {
      print(x + "s");
    }
  }
}
