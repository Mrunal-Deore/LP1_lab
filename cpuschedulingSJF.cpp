//Sjf
#include<iostream>
using namespace std;

int main()
{
    int n,temp;
    int tt=0;
    int min,d,i,j;

    float atat=0 ;
    float  awt=0 ;
    float stat=0 ;
    float swt=0;

    cout<<"Enter no of process : ";
    cin>>n;

    int a[n] ;
    int b[n] ;
    int e[n] ;
    int tat[n] ;
    int wt[n];

    cout<<"\nEnter arrival time :\n";
    for( i=0 ; i<n ; i++)
    {
       cin>>a[i];
    }

    cout<<"\nEnter burst time :\n ";
    for( i=0 ; i<n ; i++)
    {
        cin>>b[i];
    }

    for( i=0 ; i<n ; i++)
    {
        for( j=0 ; j<n ; j++)
        {
            if(b[i] > b[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    min = a[0];
    for( i=0 ; i<n ; i++)
    {
        if(min > a[i])
        {
            min = a[i] ;
            d=i;
        }
    }

    tt = min;
    e[d] = tt + b[d];
    tt = e[d];

    for( i=0 ; i<n ; i++)
    {
        if( a[i] != min)
        {
            e[i] = b[i] + tt ;
            tt = e[i];
        }
    }
    
    for( i=0 ; i<n ; i++)
    {
        tat[i] = e[i] - a[i];
        stat = stat + tat[i];
        wt[i] = tat[i] - b[i];
        swt = swt + wt[i];
    }

    atat =  stat /n ;
    awt = swt /n;

    cout<<"\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurn around Time\n";
    for( i=0 ; i<n ; i++)
    {
        cout<<"P"<<i+1<<"\t\t"<<a[i]<<"\t\t"<<b[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    } 

    cout<<"\nAWT : "<<awt<<" and ATAT : "<<atat;

    return 0;
}


/*output
Enter no of process : 5

Enter arrival time :
0
2
3
4
5

Enter burst time :
 6
2
1
9
8

Process         Arrival Time    Burst Time      Waiting Time     Turn around Time 
P1              4               9               2               11
P2              5               8               10              18
P3              0               6               0               6
P4              2               2               21              23
P5              3               1               22              23

AWT : 11 and ATAT : 16.2
*/