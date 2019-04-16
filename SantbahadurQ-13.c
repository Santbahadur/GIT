#include<stdio.h>
#include<conio.h>
void main()
{
    //Assuming arrival time=0 for all processes
    int i,n;
    int pro[15],pri[15],prio[15],bt[15],q1[15],q2[15],q3[15],b1[15],b2[15],b3[15],tat[15],wt[15];
	int x=0,y=0,z=0,p=0;
	printf("Enter the number of processes:- ");
    scanf("%d",&n);
	printf("Enter the process with  priority and burst time");
	for(i=0;i<n;i++)
	 {
	    printf("\n Enter details of process[%d]\n",i+1);
	    printf("Enter priority:-\n");
		scanf("%d",&pri[i]);
		printf("Burst time:-\n");
		scanf("%d",&bt[i]);
		pro[i]=i+1;
	 }
	for(i=0;i<n;i++)
	 {
	if(pri[i]>=1 && pri[i]<=3)
	 {
		q1[x]=pro[i];
		b3[x]=bt[i];
		x++;
	 }
	else if(pri[i]>3 && pri[i]<=6)
	 {
		q2[y]=pro[i];
		b2[y]=bt[i];
		prio[y]=pri[i];
		y++;
	 }
	else
     {
		q3[z]=pro[i];
		b1[z]=bt[i];
		z++;
	 }
    }
    printf("Processes in queue 1st for First Come First Serve\n");
   for(i=0;i<x;i++)
	{
		printf("p%d\n",q1[i]);
	}
    printf("Processes in queue 2nd for Priority Scheduling\n");
    for(i=0;i<y;i++)
	{
		printf("p%d\n",q2[i]);
	}
    printf("Processes in queue 3rd for Round Robin Scheduling\n");
	for(i=0;i<z;i++)
	{
     printf("p%d\n",q3[i]);
	}
    printf("\n");
    int rem[20],tq=4;
	printf("Processes\tTurnAroundTime\t\tWaitingTime\n");
	for(i=0;i<z;i++)
	{
		rem[i]=b1[i];
	}

   A:
    	while(1)
    	{
        int flag=0;
	for(i=0;i<z;i++)
	{
	if(p>10)
	goto B;
	else
    if(rem[i]>0)
    {
        flag=1;
        if(rem[i]>tq)
        {
        p=p+tq;
        rem[i]=rem[i]-tq;
        }
        else
            {
                p=p+rem[i];
                rem[i]=0;
                wt[i]=p-b1[i];
				}
       }
       }
       if(flag==0)
       {
       for(i=0;i<z;i++)
    {
	tat[i]=b1[i]+wt[i];
	printf("p%d\t\t\t%d\t\t\t%d\n",q3[i],tat[i],wt[i]);
}
    break;
    }
  }
   int ts,tp,j;
   B:
    for(i=0;i<y;i++)
    {
    for(j=i+1;j<x;j++)
    {
    if(prio[j]>prio[i])
    {
        tp=b2[j];
        b2[j]=b2[i];
        b2[i]=tp;
        ts=q2[j];
        q2[j]=q2[i];
        q2[i]=ts;
    }
    }
	}
     for(i=0;i<y;i++)
    {
    	if(p>20)
    	goto C;
    	else
    {
    	p=p+b2[i];
		printf("p%d\t\t\t%d\t\t\t%d\n",q2[i],p,(p-b2[i]));
    }
    }
   C:
    for(i=0;i<x;i++)
    {
    p=p+b3[i];
    printf("p%d\t\t\t%d\t\t\t%d\n",q1[i],p,(p-b3[i]));
        }
	}
