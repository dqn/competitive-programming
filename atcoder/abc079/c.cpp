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
  VAR(string, abcd);
  int A = abcd[0] - 48;
  int B = abcd[1] - 48;
  int C = abcd[2] - 48;
  int D = abcd[3] - 48;
  vector<char> op = {'+', '-'};
  each(op1, op) {
    each(op2, op) {
      each(op3, op) {
        int ans = A;
        if (op1 == '+') ans += B;
        else ans -= B;
        if (op2 == '+') ans += C;
        else ans -= C;
        if (op3 == '+') ans += D;
        else ans -= D;
        if (ans == 7) {
          cout << A << op1 << B << op2 << C << op3 << D << "=7" << endl;
          return;
        }
      }
    }
  }
}
