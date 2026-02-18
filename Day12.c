#include <stdio.h>


int main() {
    int m, n;
    int mat[100][100];
    
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    int v = 1;
    
    // Check if square
    if (m != n) 
    {
        v = 0;
    } else 
    {
      
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[j][i]) {
                    v = 0;
                    break;
                }
            }
        }
    }
    
    if (v == 1)
    {
       printf("symetric");
    }

    else
    {
        printf("Not Symmetric");
    }
    
    return 0;
}