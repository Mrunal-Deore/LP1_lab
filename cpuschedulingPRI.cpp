//Priority         //consider AT=0 (for all) if non-preemptive 
#include<iostream>
using namespace std;

struct task
{
    int tno, at, bt,wt,tat,pr;
};

void getdata(task t[], int n )
{
    for( int i=0 ; i<n ; i++)
    {
        cout<<"\nFor task "<<i+1<<" : "<<endl;
        cout<<"\tEnter task no : ";
        cin>>t[i].tno;
        cout<<"\tEnter arrival time : ";
        cin>>t[i].at;
        cout<<"\tEnter burst time : ";
        cin>>t[i].bt;
        cout<<"\tEnter priority : ";
        cin>>t[i].pr;
    }
}

void displaydata(task t[] , int n )
{
        cout<<"\n\tTask\tArrival Time\tBurst Time\tPriority"<<endl;
        for( int i=0 ; i<n ; i++)
        {
            cout<<"\n\tT"<<t[i].tno<<"\t\t"<<(t[i].at)<<"\t\t"<<(t[i].bt)<<"\t\t"<<(t[i].pr)<<endl;
        }
}

void prio(task t[] , int n )
{
    int i,j;
    task temp;
    for( i=0 ; i<n-1 ; i++)
    {
        for( j=0 ; j<n-i-1 ; j++)
        {
            if( t[j].pr > t[j+1].pr)
            {
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
            else if (t[j].pr == t[j+1].pr)
            {
                if( t[j].bt > t[j+1].bt)
                {
                    temp = t[j];
                    t[j] = t[j+1];
                    t[j+1] = temp ;
                }
            }
            
        }
    }
}

void wt_tat( task t[] , int n )
{
    t[0].wt =0 ;
    t[1].tat = t[0].bt;

    for(int i=0 ; i<n ; i++)
    {
        int ct=0 ;
        for( int j=0 ; j<i ; j++)
        {
            ct = ct + t[j].bt;
        }

        t[i].wt = ct-t[i].at;
        t[i].tat = t[i].wt + t[i].bt;
    }

    cout<<"\n\tTask\tArrival Time\tBurst Time\tWaiting Time\tTurn Around time"<<endl;
    for( int i=0 ; i<n ; i++)
    {
        cout<<"\n\tT"<<t[i].tno<<"\t\t"<<t[i].at<<"\t\t"<<t[i].bt<<"\t\t"<<t[i].wt<<"\t\t"<<t[i].tat<<endl;

    }
}

void cal_avg( task t[] , int n )
{
    float sum_wt=0;
    for( int i=0 ; i<n ; i++)
    {
        sum_wt += t[i].wt;
    }

    float avg_wt = sum_wt /n ;
    cout<<"\nAverage waiting time : "<<avg_wt;

    float sum_tat=0;
    for( int i=0 ; i<n ; i++)
    {
        sum_tat += t[i].tat;
    }
    float avg_tat = sum_tat /n;
    cout<<"\nAverage TAT : "<<avg_tat;
}

int main()
{
    task t[5];   //obj 
    int n ; 
    cout<<"\nEnter number of task : ";
    cin>>n;
    getdata( t,n );
    cout<<"\nGiven data : "<<endl;
    displaydata( t, n);

    prio( t, n);
    wt_tat(t,n );
    cal_avg(t,n);
    return 0;
}

/*output
Enter number of task : 4

For task 1 :
        Enter task no : 1
        Enter arrival time : 0
        Enter burst time : 7
        Enter priority : 4

For task 2 :
        Enter task no : 2
        Enter arrival time : 0
        Enter burst time : 4
        Enter priority : 3

For task 3 :
        Enter task no : 3
        Enter arrival time : 0
        Enter burst time : 1
        Enter priority : 2

For task 4 :
        Enter task no : 4
        Enter arrival time : 0
        Enter burst time : 3
        Enter priority : 1

Given data :

        Task    Arrival Time    Burst Time      Priority

        T1              0               7               4

        T2              0               4               3

        T3              0               1               2

        T4              0               3               1

        Task    Arrival Time    Burst Time      Waiting Time    Turn Around time 

        T4              0               3               0               3        

        T3              0               1               3               4        

        T2              0               4               4               8        

        T1              0               7               8               15       

Average waiting time : 3.75
Average TAT : 7.5
*/