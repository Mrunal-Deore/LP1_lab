//Shortest Job First - Non-Preemptive Algorithm for Task Scheduling 

import java.util.Scanner;

class task                                            //Class defining a Task
{
    int taskno;
    int arrivalTime;
    int runTime,waitingTime,tat;
    
    task()
    {
        waitingTime=0;
        tat=0;
    }
    
    void getData(int no)                                //Input of Arrival Time and Run Time of a Task
    {
        Scanner sc=new Scanner(System.in);
        taskno=no;
        System.out.print("\nEnter Arrival Time for Task "+no+" : ");
        arrivalTime=sc.nextInt();
        System.out.print("Enter Run Time for Task "+no+" : ");
        runTime=sc.nextInt();
    }

    void displayData()                                  //Display of Task Details
    {
       System.out.println(taskno+"\t\t"+arrivalTime+"\t\t"+runTime+"\t\t"+waitingTime+"\t\t\t"+tat);
    }
}

class CPUSystem                                           //Task Scheduler
{
    int numOfTasks;
    task[] obj=new task[100];                              //Array of 'Task' type objects
    float tatAvg,waitTimeAvg;
    
    CPUSystem(int number)                                  //Constructor
    {
        numOfTasks=number;
        tatAvg=0;
        waitTimeAvg=0;
        
        for(int i=0;i<numOfTasks;i++)
        {
            obj[i]=new task();
            obj[i].getData(i+1);
        }
    }
    
    void calculations()                                     //Calculating Waiting Time and TAT for each task                     
    {
        for(int i=0;i<numOfTasks;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                obj[i].waitingTime+=obj[j].runTime;
            }
            obj[i].waitingTime-=obj[i].arrivalTime;
            obj[i].tat=(obj[i].waitingTime)+(obj[i].runTime);
        }
    }
    
    void display()
    {
        System.out.println("Task\t\tArrival Time\tRuntime\t\tWaiting Time\t\tTurn Around Time");
    
        for(int i=0;i<numOfTasks;i++)
        {
            obj[i].displayData();
        }
    }
    
    void sort()                                              //Sorting the tasks on the basis of Run Time                                                   
    {
        task temp=new task();
        for(int i=0;i<numOfTasks;i++)
        {
            for(int j=i+1;j<numOfTasks;j++)
            {
                if(obj[i].runTime>obj[j].runTime)
                {
                    temp=obj[i];
                    obj[i]=obj[j];
                    obj[j]=temp;
                }
                else if(obj[i].runTime==obj[j].runTime)
                {
                	if(obj[i].arrivalTime>obj[j].arrivalTime)
                	{
                		temp=obj[i];
                    	obj[i]=obj[j];
                    	obj[j]=temp;
                    }
            
            	}
            }   
        }
    }
    
    void calAverage()                           //Calculating Average Waiting Time & Average TAT
    {
        for(int i=0;i<numOfTasks;i++)
        {
            tatAvg+=obj[i].tat;
            waitTimeAvg+=obj[i].waitingTime;
        }
        System.out.println("Average Waiting Time : "+waitTimeAvg/numOfTasks);
        System.out.println("Average Turn Around Time : "+tatAvg/numOfTasks);
}

}

public class SJFnonpreemp
{
    public static void main(String args[])
    {
        int num;
        Scanner sc=new Scanner(System.in);
        
        System.out.print("Enter the number of tasks you want to schedule : ");
        num=sc.nextInt();
        
        CPUSystem cpu=new CPUSystem(num);
        cpu.sort();
        cpu.calculations();
        System.out.println("\n\t\t\t\tTasks List");
        System.out.println("--------------------------------------------------------------------------------------------");
        cpu.display();
        System.out.println("--------------------------------------------------------------------------------------------");
        cpu.calAverage();
        
    }
}
