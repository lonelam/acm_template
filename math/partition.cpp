#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
bool check(int x) {
  for (int i=2; i*i<=x; i++)
    if (x%i==0)
      return 0;
  return 1;
}
int p[100000];
inline int calc(int x) {
  return x*(x*3-1)/2;
}
int main() {
  p[0]=1;
  for (int i=1; i<100000; i++) {
    for (int j=1,k=1; calc(j)<=i; j++,k*=-1) {
      p[i]+=k*p[i-calc(j)];
      if (p[i]<0)
        p[i]+=1000000;
      if (p[i]>=1000000)
        p[i]-=1000000;
      if (calc(-j)<=i)
        p[i]+=k*p[i-calc(-j)];
      if (p[i]<0)
        p[i]+=1000000;
      if (p[i]>=1000000)
        p[i]-=1000000;
    }
    if (!p[i])
      printf("%d\n",i);
  }
  return 0;
}

