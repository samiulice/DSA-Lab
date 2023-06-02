#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

int Insert_element(int a[],int n, int item, int positon)
{
    if(n == MAX_SIZE){
        printf("Array is full!!");
        return n;
    }
    int i,temp;
    for(i = n; i >= positon-1; i--){
        a[i] = a[i-1];
    }
    a[positon-1] = item;
    
    return n+1;
}

int Delete_position(int a[], int n, int position)
{
    if(n == 0 || position > n){
        printf("Unable to delete\n");
        return n;
    }
    for(int i = position; i < n; i++){
        a[i-1] = a[i];
    }
    return n-1;
}

int Delete_element(int a[], int n, int item)
{
    for(int i = 0; i < n; i++){
        if(a[i] == item){
            n = Delete_position(a, n, i+1);
            return n;
        }
    }
    printf("Element not found\n");
    return n;
}

void array_print(int a[], int n)
{
    if(n == 0){
        printf("Empty Array!!\n");
    }
    for(int i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main ()
{
    int a[MAX_SIZE], n, t=1, i, item, position;
//Creating Array:    
    printf("Size of the Array:");
    scanf("%d", &n);

    printf("Enter Array Elements:");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    array_print(a, n);
//Array Operations:
    while(1)
    {
        
        printf("Prepend(1)\nAppend(2)\nInsert Element at any position(press 3)\nDelete Element of the particular positon(press 4)\nDelete particular Element(press 5)\nExit Program(press 0)\n");

        scanf("%d", &t);
        
        //Prepend:
        if(t == 1){
            printf("Enter Item: ");
            scanf("%d", &item);
            n = Insert_element(a, n, item, 1);
        

        }
        //Append:
        else if(t == 2){
            printf("Enter Item: ");
            scanf("%d", &item);
            if(n == MAX_SIZE){
                printf("Array is full!!");
            }
            else{
                a[n++] = item;
            
            }
            
        }
        //Insert
        if(t == 3){
            printf("Enter item: ");
            scanf("%d", &item);
            printf("Enter Item Position: ");
            scanf("%d", &position);
            n = Insert_element(a, n, item, position);
        
        }
        //Delete_Position
        else if(t == 4){
            printf("Enter Item Position: ");
            scanf("%d", &position);
            n = Delete_position(a, n, position);
        
        }
        //Delete Particular Element
        else if(t == 5){
            printf("Enter Item: ");
            scanf("%d", &item);
            n = Delete_element(a, n, item);
        }
        //Close Program
        else if(t == 0){
            break;
        }
        array_print(a, n);
        
    }

    return 0;
}