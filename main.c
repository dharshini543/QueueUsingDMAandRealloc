#include <stdio.h>
#include<stdlib.h>

int*queue;
int front = -1;
int rear = -1;
int count,newsize;

void enqueue(int num)
{
    if(rear == count-1)
    {
        int input;
        printf("Queue size exceeded\n");
        printf("Want to resize...press 1 else 0\n");
        scanf("%d",&input);
        if(input == 1)
        {
        printf("Enter newsize of queue\n");
        scanf("%d",&newsize);
        queue = (int*)realloc(queue,newsize*sizeof(int));
        count = newsize;
        rear++;
        queue[rear]= num;
        }
        else
        {
            return 1;
        }
    }
    else if(front==-1 && rear==-1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is Empty\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("The dequeued element from queue is %d\n",queue[front]);
        front++;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Empty Queue\n");
    }
    else
    {
        printf("Queue Elements are\n");
        for(int i = front;i < rear+1;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
int main()
{
    int choice,num;
    printf("Enter size of Queue\n");
    scanf("%d",&count);

    queue =(int*)malloc(count*sizeof(int));
    while(1)
    {
        printf("Enter 1 to enqueue\n 2 to dequeue\n 3 to Display\n 4 to exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:printf("Enter value to add to the queue\n");
            scanf("%d",&num);
            enqueue(num);
            break;

        case 2:dequeue();
            break;

        case 3:display();
            break;

        case 4:printf("Exited from Queue\n");
            break;

        default:printf("Read the instructions and enter valid number\n");
            break;
        }
    }
    free(queue);

    return 0;
}
