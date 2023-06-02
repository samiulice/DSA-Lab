#include<stdio.h>

int main ()
{
    int n, i, j, temp;
    int a[100];
    printf("Enter the array size: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    //Bubble sort:
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("After sorting:\t");
    for(i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}