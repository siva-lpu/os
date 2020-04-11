#include<stdio.h>
 
int main()
{
      int i,a, total_p
	        , t_time = 0
	        
	, x, flag= 0,quantum;
      int arrival[10], burst[10], temp[10];
      
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &total_p);
      x = total_p;
      
      for(i = 0; i < total_p; i++)                                //
      {                                                           //
            printf("\nEnter Details of Process[%d]\n", i + 1);    //
                                                                  //
            printf("Arrival Time:\t");                 //       reading arrival time and burdt time of each process
 
            scanf("%d", &arrival[i]);                            //
 
            printf("Burst Time:\t");                             //
 
            scanf("%d", &burst[i]);                              //
 
            temp[i] = burst[i];
      }
 
      printf("\nEnter Time Quantum:\t");                         //   reading quantum
      scanf("%d", &quantum);
      
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(t_time = 0, i = 0; x != 0;)
      {
            if(temp[i] <= quantum && temp[i] > 0)
            {
                  t_time = t_time + temp[i];
                  temp[i] = 0;
                  flag = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - quantum;
                  t_time = t_time + quantum;
            }
            if(temp[i] == 0 && flag == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst[i],/*turnaround time-->*/ t_time - arrival[i],/*waiting time -->*/ t_time - arrival[i] - burst[i]);
                  a=i;
                  
                  flag = 0;
            }
            if(i == total_p - 1)
            {
                  i = 0;
            }
            else if(arrival[i + 1] <= t_time)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      printf("\n total time taken is %d sec",t_time - arrival[a]);     //................ TOATAL TIME TAKEN..............
      return 0;
}
