int m[10],a[10];//`$x\ mod\ m_i =a_i$`
bool solve(int &m0,int &a0,int m,int a) {
  int y,x;
  int g=ex_gcd(m0,m,x,y);
  if (abs(a-a0)%g) return 0;
  x*=(a-a0)/g;
  x%=m/g;
  a0=(x*m0+a0);
  m0*=m/g;
  a0%=m0;
  if (a0<0) a0+=m0;
  return 1;
}
int MLES() {
  bool flag=1;
  int m0=1,a0=0;
  for (int i=0; i<n; i++)
    if (!solve(m0,a0,m[i],a[i])) {
      flag=0;
      break;
    }
  if (flag)
    return a0;
  else
    return -1;
}
