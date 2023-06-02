#include<stdio.h>
#define Q_size 5

typedef struct {
    int data[Q_size+1];
    int head, tail;
} Queue;

void enqueue(Queue *Q, int item)
{
    if((Q->tail + 1) % (Q_size + 1) == Q->head){
        printf("Queue is full\n");
    }
    else{
        Q->data[Q->tail] = item;
        Q->tail = (Q->tail + 1) % (Q_size + 1);
    }
}

void dequeue(Queue *Q)
{
    if(Q->tail == Q->head){
        printf("Queue is empty\n");
    }
    else {
        printf("%d\n", Q->data[Q->head]);
        Q->head = (Q->head + 1) % (Q_size + 1);
    }
}

int main ()
{
    Queue Q;
    Q.head = 0;
    Q.tail = 0;
    int t, num;
    while(1){
        printf("0-1-2:Close Program-Enqueue-Dequeue: ");
        scanf("%d", &t);

        if(t==0){
            return 0;
        }
        else if(t == 1){
            printf("Enter Number: ");
            scanf("%d", &num);
            enqueue(&Q, num);
        }
        else{
            dequeue(&Q);
        }
    }
    return 0;
}
