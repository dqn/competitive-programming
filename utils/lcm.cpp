int gcd(int a, int b) {
  while(a^=b^=a^=b%=a);
  return b;
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}
