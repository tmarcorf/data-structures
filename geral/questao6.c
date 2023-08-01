#include <stdio.h>
#include <math.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) 
  {
    int A, B, C, k;

    scanf("%d%d%d%d", &A, &B, &C, &k);
    
    int x0 = ceil((-B + sqrt(B * B - 4 * A * (C - k))) / (2 * A));
    printf("%d\n", x0);
  }
  return 0;
}