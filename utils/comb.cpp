ll power(ll a,ll n){ll ret=1;for(;n>0;n>>=1,a=a*a%MOD)if(n%2==1)ret=ret*a%MOD;return ret;}
ll comb(ll n,ll r){ll x=1,y=1;rep(i,0,r){x=x*(n-i)%MOD;y=y*(i+1)%MOD;}return x*power(y,MOD-2)%MOD;}
