#include<iostream>
using namespace std;

struct Process
{
    int id,at,bt, wt,tat;
};

void find_wt(Process p[] , int n)
{
    p[0].wt =0 ;
    for( int i=1 ; i<n ; i++)
    {
        p[i].wt =p[i-1].wt + p[i-1].bt;
    }
}

void find_tat( Process p[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
    }
}

void find_avg( Process p[] , int n)
{
    double total_wt =0;
    double total_tat =0;
    
    for(int i=0 ; i<n ; i++)
    {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    double avg_wt = total_wt / n;
    double avg_tat = total_tat/n;

    cout<<"\nAverage waiting time : "<<avg_wt;
    cout<<"\nAverage TAT : "<<avg_tat;
}

int main()
{
    int n ;
    cout<<"\nEnter the no of processes : ";
    cin>>n;

    Process p[n];

    cout<<"\nEnter arrival time and burst time for each process : "<<endl;
    for(int i=0 ; i<n ;i++)
    {
        p[i].id = i+1;
        cin>>p[i].at>>p[i].bt;
    }

    for(int i=0 ;i<n ; i++)
    {
        for( int j=i+1 ; j<n ; j++)
        {
            if( p[i].at > p[j].at)
            {
                //swap the process
                Process temp = p[i];
                p[i] = p[j];
                p[j]  = temp;
            }
        }
    }
    
    find_wt( p,n);
    find_tat(p,n);

    cout<<"\nProcess\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurnaround time"<<endl;
    for( int i=0 ; i<n ; i++)
    {
        cout<<p[i].id<<"\t\t"<<p[i].at<<"\t\t\t"<<p[i].bt<<"\t\t\t"<<p[i].wt<<"\t\t\t"<<p[i].tat<<endl;
    }

    find_avg( p,n);

    return 0;
}
/*output
Enter the no of processes : 5

Enter arrival time and burst time for each process :
0
6
2
2
3
1
4
9
5
8

Process         Arrival Time            Burst Time              Waiting Time            Turnaround time
1               0                       6                       0                       6
2               2                       2                       6                       8
3               3                       1                       8                       9
4               4                       9                       9                       18
5               5                       8                       18                      26

Average waiting time : 8.2
Average TAT : 13.4
*/