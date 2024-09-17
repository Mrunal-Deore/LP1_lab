//Round robin
#include<iostream>
using namespace std;

void find_wt(int p[] , int n , int bt[] , int wt[] , int quantum)
{
    //burst time
    int m_bt[n];
    for( int i=0 ; i<n ; i++)
    {
        m_bt[i] = bt[i];
    }
    int t=0;    //current time
    
    //keep traversing processes in RR manner 
    while(1)
    {
         bool done =true;

         //traverse all processes one by one repeatedly
         for( int i=0 ; i<n ; i++)
         {
            /*if burst time of a process is greater than 
            zero then only need to apply process further*/
            if(m_bt[i] > 0 )
            {
                done = false ;   //there is a pending process 
            
            if( m_bt[i] > quantum)
            {
                t += quantum ;
                m_bt[i] -= quantum; 
            }

            /*if burst time is smaller than or equal to quantum.
            last cycle for this process*/

            else
            {
                //increase the value of t
                t = t + m_bt[i];

                //waiting time is current time minus time
                wt[i] = t- bt[i];

                /*as the processs fully get processed make its 
                remainig burst time zero*/
                m_bt[i] = 0;
            }
           }
         }

         //if all processes are done 
         if ( done == true)
         break;
    }
}

//function to calculate turn around time 
void find_tat( int p[] , int n , int bt[] , int wt[] , int tat[])
{
    for( int i=0 ; i<n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

//function to calculate average time
void find_avg( int p[] , int n , int bt[] , int quantum)
{
    int wt[n] ,  tat[n] , total_wt=0 , total_tat=0;

    find_wt( p,n,bt,wt,quantum);
    
    find_tat( p , n , bt ,wt ,tat);

    cout<<"Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n";

    for( int i=0 ; i<n ; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout<<"P"<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }

    cout<<"\nAverage waiting time : "<<(float)total_wt /(float)n;
    cout<<"\nAverage TAT time : "<<(float)total_tat /(float)n;
}

int main()
{
    int processes[] = {1,2,3};
    int n = sizeof processes / sizeof processes[0];

    int burst_time[] = {10 ,5,8};

    int quantum = 2;

    find_avg( processes , n, burst_time , quantum);
    return 0;
}
/*output
Process         Burst Time      Waiting Time    Turnaround Time
P1              10              13              23
P2              5               10              15
P3              8               13              21

Average waiting time : 12
Average TAT time : 19.6667
*/