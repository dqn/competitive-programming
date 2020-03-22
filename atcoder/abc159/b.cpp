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

bool is_kaibun(string s) {
  rep(i, 0, (int)s.length() / 2) {
    if (s[i] != s[s.length() - i - 1]) {
      return false;
    }
  }
  return true;
}

void solve() {
  VAR(string, S);
  int N = S.length();

  string s1 = S.substr(0, (N - 1) / 2);
  string s2 = S.substr((N + 3) / 2 - 1, N - ((N + 3) / 2) + 1);
  if (s1 == s2 && is_kaibun(s1)) {
    print("Yes");
  } else {
    print("No");
  }
}
