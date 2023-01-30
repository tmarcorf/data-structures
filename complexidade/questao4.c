#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1005

int n, k, maxL, count;
char world[MAX][MAX];

void countThieves(int i, int j) 
{
    int l;
    int left = j - k, right = j + k;
    for (l = j; l >= left && l >= 0; l--) 
    {
        if (world[i][l] == 'L') 
        {
            count++;
            break;
        }
        if (world[i][l] == 'P') break;
    }

    int r;
    for (r = j; r <= right && r < n; r++) 
    {
        if (world[i][r] == 'L') 
        {
            count++;
            break;
        }
        if (world[i][r] == 'P') break;
    }
}

int main() 
{
    int t;
    scanf("%d", &t);
    while (t--) 
    {
        scanf("%d%d", &n, &k);
        memset(world, 0, sizeof(world));
        maxL = 0;
        int i;
        int j;
        for (i = 0; i < n; i++) 
        {
            for (j = 0; j < n; j++) {
                scanf(" %c", &world[i][j]);
                if (world[i][j] == 'P') 
                {
                    count = 0;
                    countThieves(i, j);
                    if (count > maxL) maxL = count;
                }
            }
        }
        printf("%d\n", maxL);
    }
    return 0;
}