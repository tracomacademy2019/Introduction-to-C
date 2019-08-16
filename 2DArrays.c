#include <stdio.h>
#include <stdlib.h>

int main()
{
    int disp[3][2];

    int i, j;

    for(i = 0; i<3; i++){
        for(j = 0; j< 2; j++){
            printf("Enter value for display[%d][%d]: ", i, j);
            scanf("%d", &disp[i][j]);
        }
    }

    printf("2D array elements:\n");
    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            printf("%d\t", disp[i][j]);
            if(j==1){
                printf("\n");
            }
        }
    }

    //printf("Hello world!\n");
    return 0;
}
