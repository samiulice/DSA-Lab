#include<stdio.h>

int main ()
{
    int a[1000], i, num, size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    printf("\nEnter sorted array element: ");
    for(i = 0; i < size; i++){
        scanf("%d", &a[i]);
    }
    printf("Find Element: ");
    scanf("%d",&num);

    int low = 0, high = size-1, mid;
    while(low <= high){
        mid = (high+low)/2;
        if(a[mid] == num){
            printf("Element position is : %d\n", mid+1);
            return 0;
        }
        else if(a[mid] < num){
            low = mid + 1;
        }
        else {
            high = mid-1;
        }
    }
    printf("Element not found in the array\n");
    return 0;
}