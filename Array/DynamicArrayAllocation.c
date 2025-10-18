#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int m = 3;
    int **array ;
    
    array = (int**)malloc(n * sizeof(int *));
    for (int i = 0; i < n ; i++){
        array[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n ; i++){
        for (int j = 0 ; j<m;j++){
            scanf("%d",&array[i][j]);
        }
    }
    printf("[");
    for (int i = 0; i < n ; i++){
        printf("{");
        for (int j = 0 ; j<m; j++){
            printf("%d, ",array[i][j]);
        }
        printf("},\n");
    }
    printf("]");
    
    int new_n = 5;
    int new_m = 5;
    
    for (int i = 0; i < n ; i++){
        int *temp_row  = realloc(array[i], new_m*sizeof(int));
        array[i] = temp_row; 
    }
    
    int **temp_array = (int **)realloc(array, new_n * sizeof(int));
    array = temp_array;
    
    for(int i = n ; i < new_n ; i ++){
        array[i]=(int *)malloc(new_m * sizeof(int));
    }
    
    printf("\n\n\n\n[");
    for (int i = 0; i < new_n ; i++){
        printf("{");
        for (int j = 0 ; j < new_m; j++){
            printf("%d, ",array[i][j]);
        }
        printf("},\n");
    }
    printf("]");
    
    
    
    return 0;
}
