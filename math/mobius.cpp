const int maxn = 1000000 + 100;
int primes[maxn], ptot;
int mu[maxn];
bool nprime[maxn];
void init()
{
  nprime[1] = true;
  mu[1] = 1;
  for (int i = 2; i < maxn; i++)
  {
    if (!nprime[i])
    {
      primes[ptot++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < ptot && i * primes[j] < maxn; j++)
    {
      nprime[i * primes[j]] = true;
      if (i % primes[j] == 0)
      {
        mu[i * primes[j]] = -mu[i];
        break;
      }
    }
  }
}
