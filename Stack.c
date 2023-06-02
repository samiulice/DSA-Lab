#include <stdio.h>
#define STACK_MAX 5

typedef struct
{
    int top;
    int data[STACK_MAX];
} Stack;

void push (Stack *s, int num)
{
    if(s->top == STACK_MAX){
        printf("Stack is full\n");
        return;
    }
    s->top = s->top +1;
    s->data[s->top] = num;

}

void pop(Stack *s)
{
    if(s->top == -1){
        printf("Stack is empty\n");
        return;
    }
    
    printf("%d\n", s->data[s->top]);
    s->top = s->top - 1;
}
int main ()
{
    Stack s;
    int t, num;
    s.top =-1;

    while(1)
    {
        printf("Push[1]\tPOP[2]\tClose Program[0]\n");
        scanf("%d", &t);
        if(t == 0){
            return 0;
        }
        else if(t==1){
            printf("\nEnter Number: ");
            scanf("%d", &num);
            push(&s, num);
        }
        else{
            pop(&s);
        }
    }
    return 0;
}
