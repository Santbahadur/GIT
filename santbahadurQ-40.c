#include<stdio.h>
#include<conio.h>
void main()
    {
	int i,j,p;
	int bt[15],pro[15],ta[15],pri[15],tat,temp;
    for(i=0;i<5;i++)
	 {
        printf("Enter details of process[%d]\n",i+1);
		printf("Enter Burst Time:\n");
        scanf("%d",&bt[i]);
		printf("Enter Priority:\n");
		scanf("%d",&pri[i]);
		pro[i]=i+1;
	 }
	for(i=0;i<5;i++)
	 {
        p=i;
		for(j=i+1;j<5;j++)
		{
        if(bt[j]<bt[p])
        {
        p=j;
        }
        else if(bt[j]==bt[p])
        {
        if(pri[j]>pri[i])
        {
        p=j;
        }
        }
		}
		temp=bt[i];
		bt[i]=bt[p];
		bt[p]=temp;

		temp=pro[i];
		pro[i]=pro[p];
		pro[p]=temp;
	    }
	   tat=0;
		for(j=0;j<5;j++)
		{
		tat=tat+bt[j];
		ta[j]=tat;
	    }
	    printf("Processes\tBurstTime\tTurnAroundTime\n");
	    for(i=0;i<5;i++)
	    {
		printf("p%d:",pro[i]);
		printf("\t\t");
		printf("%d",bt[i]);
		printf("\t\t");
		printf("%d",ta[i]);
		printf("\n");
	    }
      }
