#include<stdio.h>
int main()
{
    int i,n ,qt, count=0,temp,sq=0,bt[20], wt[20], tat[20], rem_bt[20];
    float awt=0,atat=0;
    
    printf("enter the no. of process : ");
    scanf("%d",&n);

    printf("\n enter the burst time of the process \n");
    for(i=0;i<n;i++)
    {
        printf("p[%d]",i+1);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
        
    }
    printf("enter quantum time");
    scanf("%d",&qt);
    while(i)
    {
        for(i=0,count=0; i<n;i++)
        {
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
            if(rem_bt[i]>qt)
           {
             rem_bt[i]=rem_bt[i]-qt;
           }
           if(rem_bt[i]>=0)
           {
            temp=rem_bt[i];
            rem_bt[i]=0;
           }
           sq=sq+temp;
           tat[i]=sq;
        }
        if(n==count)
        {
            break;
        }
        printf("\n process\tburst time\twaiting time\tturnaround time");
        for(i=0;i<n;i++)
        {
            wt[i]=tat[i]-bt[i];
            awt=awt+wt[i];
            atat=atat+tat[i];
            printf("\np[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
        }
        awt=awt/n;
        atat=atat/n;
        printf("\naverage waiting time : %f",awt);
        printf("\average turnaround time : %f",atat);
        return 0;
    }
}