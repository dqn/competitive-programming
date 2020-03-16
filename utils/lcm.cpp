int gcd(int a,int b){while(a^=b^=a^=b%=a);return b;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
