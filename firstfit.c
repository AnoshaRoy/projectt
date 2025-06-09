#include<stdio.h>
struct process
{
    int psize,pid,blkno;
}p[20];
struct memory
{
    int mid,msize,allc,wasted
}m[20];
void main()
{
    int i,pn,mn,j;
    printf("Enter number of Memory Blocks");
    scanf("%d",&mn);
    for(i=0;i<mn;i++)
    {
        printf("Enter Memory ID and Size");
        scanf("%d%d",m[i].mid,m[i].msize);
        m[i].allc=-1;
        m[i].wasted=m[i].msize;
    }
    printf("Enter number of processes");
    scanf("%d",&pn);
    for(i=0;i<pn;i++)
    {
        printf("Enter Process ID and Size");
        scanf("%d%d",p[i].pid,p[i].psize);
        p[i].blkno=-1;
    }
    for(i=0;i<pn;i++)
    {
        for(j=0;j<mn;j++)
        {
            if(m[j].allc==-1&&m[j].msize>=p[i].psize)
            {
                p[i].blkno=m[j].mid;
                m[j].allc=1;
                break;
            }
        }
    }
    for(i=0;i<pn;i++)
    {
        for(j=0;j<mn;j++)
        {
            if(p[i].blkno==m[j].mid)
            {
                m[j].wasted=m[j].msize-p[i].psize;
                break;
            }
        }
    }
}