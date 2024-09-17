//Shortest Job First - Preemptive Algorithm for Task Scheduling
import java.util.Scanner;

class task				//Class defining a task
{
    int taskno;
    int arrivalTime;
    int runTime,waitingTime,tat,completionTime;
    
    task()
    {
    	arrivalTime=0;
    	runTime=0;
        waitingTime=0;
        tat=0;
        completionTime=0;
    }
    
    void getData(int no)		//input of arrival time and burst time from user 
    {
        Scanner sc=new Scanner(System.in);
        taskno=no;
        System.out.print("\nEnter Arrival Time for Task "+no+" : ");
        arrivalTime=sc.nextInt();
        System.out.print("Enter Run Time for Task "+no+" : ");
        runTime=sc.nextInt();
    }

    void displayData()		//display a particular task
    {
       System.out.println(taskno+"\t\t"+arrivalTime+"\t\t"+runTime+"\t\t"+waitingTime+"\t\t\t"+tat);
    }
}

class CPUSystem						//task scheduler
{
    int numOfTasks;
    task[] obj=new task[100];
    float tatAvg,waitTimeAvg;
    int totalTime;
    
    CPUSystem(int number)
    {
        numOfTasks=number;
        tatAvg=0;
        waitTimeAvg=0;
        totalTime=0;
        
        for(int i=0;i<numOfTasks;i++)
        {
            obj[i]=new task();		//creation of tasks
            obj[i].getData(i+1);	//input of data
        }
    }
    
    void calculations()
    {
    	int arrivalData[]=new int[numOfTasks];		//Array to store all arrival time
    	int runTimeData[]=new int[numOfTasks];		//Array to store all run time
    	int completed=0;							//variable showing no. of task completed
    	int minBurstTime=1000;			//storing miniumum burst time out of tasks
    	int currentTime=0;
    	int shortestTask=1;
    	boolean check=false;
    	
        for(int i=0;i<numOfTasks;i++)
        {
        	//copying burst time and arrival time of all tasks into arrays 
        	arrivalData[i]=obj[i].arrivalTime;
        	runTimeData[i]=obj[i].runTime;
        }
        
        //loop until all process get executed
        while(completed!=numOfTasks)
        {
        	//finding the process with minimum runTime /remaining Time 
        	for(int j=0;j<numOfTasks;j++)
        	{
        		if(runTimeData[j]<minBurstTime && runTimeData[j]>0 &&( arrivalData[j]<=currentTime ))
        		{
        			minBurstTime=runTimeData[j];
        			shortestTask=j;	
        			check=true;
        		}
        	} 
        	
        	if(check==false)
        	{
        		currentTime++;
        		continue;
        	}
        	
        	runTimeData[shortestTask]--;				//reduce remaining time by one second
        	
        	//update minimum
        	minBurstTime=runTimeData[shortestTask];
        	if(minBurstTime==0)
        	{
        		minBurstTime=1000;
        	}
        	
        	//If process completes execution
     		if(runTimeData[shortestTask]==0)
     		{
     			//task compeleted 
     			completed++;
     			check=false;
     			
     			//store completion time of the process
     			obj[shortestTask].completionTime=currentTime+1;
     			System.out.println("CT for "+shortestTask+" is : "+obj[shortestTask].completionTime);
     		
     			//calculate waiting Time 
     			obj[shortestTask].waitingTime=(obj[shortestTask].completionTime)-(obj[shortestTask].runTime)-(obj[shortestTask].arrivalTime);
     			
     			
     			if(obj[shortestTask].waitingTime<0)
     			{
     				obj[shortestTask].waitingTime=0;
     			}
     		}
            currentTime++;
        }
        
        for(int i=0;i<numOfTasks;i++)
        {
            //calculating turn around time
        	obj[i].tat=(obj[i].waitingTime)+(obj[i].runTime);
        }
    }
    
    void display()
    {
    	//table display
        System.out.println("Task\t\tArrival Time\tRuntime\t\tWaiting Time\t\tTurn Around Time");
    
        for(int i=0;i<numOfTasks;i++)
        {
            obj[i].displayData();
        }
    }
    
    void calAverage()                       //Calculating Average Waiting Time & Average TAT
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

public class SJFpreemp
{
    public static void main(String args[])
    {
        int num;
        Scanner sc=new Scanner(System.in);
        
        System.out.print("Enter the number of tasks you want to schedule : ");
        num=sc.nextInt();
        
        CPUSystem cpu=new CPUSystem(num);
       
        cpu.calculations();
        
        System.out.println("\n\t\t\t\tTasks List");
        System.out.println("--------------------------------------------------------------------------------------------");
        cpu.display();
        System.out.println("--------------------------------------------------------------------------------------------");
        
        cpu.calAverage();
        
    }
}
/*output
Enter the number of tasks you want to schedule : 4

Enter Arrival Time for Task 1 : 4
Enter Run Time for Task 1 : 7

Enter Arrival Time for Task 2 : 0
Enter Run Time for Task 2 : 4

Enter Arrival Time for Task 3 : 2
Enter Run Time for Task 3 : 1

Enter Arrival Time for Task 4 : 3
Enter Run Time for Task 4 : 3
CT for 2 is : 3
CT for 1 is : 5
CT for 3 is : 8
CT for 0 is : 15

                                Tasks List
--------------------------------------------------------------------------------------------
Task            Arrival Time    Runtime         Waiting Time            Turn Around Time
1               4               7               4                       11
2               0               4               1                       5
3               2               1               0                       1
4               3               3               2                       5
--------------------------------------------------------------------------------------------
Average Waiting Time : 1.75
Average Turn Around Time : 5.5
*/