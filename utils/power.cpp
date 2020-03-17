ll power(ll a,ll n){ll ret=1;for(;n>0;n>>=1,a=a*a%MOD)if(n%2==1)ret=ret*a%MOD;return ret;}
