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
  VAR(string, S, T);
  int sl = S.length();
  int tl = T.length();
  vector<string> v;
  rep(i, 0, sl - tl + 1) {
    bool ok = true;
    rep(j, 0, tl) {
      if (S[i + j] != T[j] && S[i + j] != '?') {
        ok = false;
        break;
      }
    }
    if (ok) {
      v.push_back(S.substr(0, i) + T + S.substr(i + tl, sl - i - tl));
    }
  }
  if (v.size()) {
    sort(all(v));
    replace(all(v[0]), '?', 'a');
    print(v[0]);
  } else {
    print("UNRESTORABLE");
  }
}
