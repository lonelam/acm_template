//Self match
int j = 0;
while (j < lb && b[j] == b[j + 1])
  j++;
p[0] = lb, p[1] = j;
int k = 1;
for (int i = 2; i < lb; i++) {
  int Len = k + p[k] - 1, L = p[i - k];
  if (L < Len - i + 1)
    p[i] = L;
  else {
    j = max(0, Len - i + 1);
    while (i + j < lb && b[i + j] == b[j])
      j++;
    p[i] = j, k = i;
  }
}
//Match
j = 0;
while (j < la && j < lb && a[j] == b[j])
  j++;
eKMP[0] = j;
k = 0;
for (int i = 1; i < la; i++) {
  int Len = k + eKMP[k] - 1, L = p[i - k];
  if (L < Len - i + 1)
    eKMP[i] = L;
  else {
    j = max(0, Len - i + 1);
    while (i + j < la && j < lb && a[i + j] == b[j])
      j++;
    eKMP[i] = j, k = i;
  }
}
