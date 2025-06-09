#include<stdio.h>
#include<stdlib.h>
int empty,full=0,mutex=1,i=0,j=0,size,b[20];
int wait(int s)
{
    while(s<=0)
    {
        //busy waiting
    }
    s--;
    return s;
}
int signal(int s)
{
    s++;
    return s;
}
void producer()
{   int item;
    printf("Enter item to be produced:");
    scanf("%d",&item);
    empty=wait(empty);
    mutex=wait(mutex);
    b[i]=item;
    i=(i+1)%size;
    mutex=signal(mutex);
    full=signal(full);
}
void consumer()
{
    full=wait(full);
    mutex=wait(mutex);
    printf("The item consumed is %d",b[j]);
    j=(j+1)%size;
    mutex=signal(mutex);
    empty=signal(empty);
}
void main()
{
    int ch;
    printf("Enter the size of buffer ");
    scanf("%d",&size);
    empty=size;
    printf("Enter the choices\n1.Producer\n2.Consumer\n3.Status\n4.Exit\n");
    do
    {
        printf("Enter the choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            if((mutex==1)&&(empty!=0))
            {
                producer();
            }
            else
            {
                printf("Buffer is full\n");
            }
            break;
            case 2:
            if((mutex==1)&&(full!=0))
            {
                consumer();
            }
            else{
                printf("Buffer is empty\n");
            }
            break;
            case 3:
            {
                printf("Empty space in buffer is %d\n",empty);
            }
            break;
            case 4:
            break;
            default:
            printf("Invalid choice");
            break;
        }
    } while (ch!=4);
}
