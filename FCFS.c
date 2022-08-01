#include<stdio.h>

void main()
{
    int no_of_process, temp = 0, temp2 = 0, temp3 = 0;
    float total_turnAround_Time = 0, total_waiting_Time = 0;
    printf("Enter No of Process:    ");
    scanf("%d", &no_of_process);
    int BurstTime[no_of_process], ArrivalTime[no_of_process], completion_time[no_of_process], turnAround_Time[no_of_process], waiting_Time[no_of_process];

    // Take Values
    for(int i=0;i<no_of_process;i++){
        printf("Enter %d Process Arrival Time and Burst Time:   ", i+1);
        scanf("%d", &ArrivalTime[i]);
        scanf("%d", &BurstTime[i]);
    }
    for (int step = 0; step < no_of_process - 1; ++step) {
        for (int i = 0; i < no_of_process - step - 1; ++i) {
            if (ArrivalTime[i] > ArrivalTime[i + 1]) {
                temp = ArrivalTime[i];
                ArrivalTime[i] = ArrivalTime[i + 1];
                ArrivalTime[i + 1] = temp;
                temp2 = BurstTime[i];
                BurstTime[i] = BurstTime[i + 1];
                BurstTime[i + 1] = temp2;
            }
        }
    }
    // Calculate Completion Time
    completion_time[0] = ArrivalTime[0]+BurstTime[0];
    for(int i=1;i<no_of_process;i++){
        temp3=0;
        if(completion_time[i-1]<ArrivalTime[i])
        {
            temp3 = ArrivalTime[i]-completion_time[i-1];
        }
        completion_time[i] = completion_time[i-1]+BurstTime[i]+temp3;
    }

    //Calculate Turn Around Time
    for(int i=0;i<no_of_process;i++)
    {
        turnAround_Time[i] = completion_time[i] - ArrivalTime[i];
        total_turnAround_Time += turnAround_Time[i];
    }
    total_turnAround_Time=total_turnAround_Time/no_of_process;
    //Calculate Waiting Time
    for(int i=0;i<no_of_process;i++)
    {
        waiting_Time[i] = turnAround_Time[i] - BurstTime[i];
        total_waiting_Time+=waiting_Time[i];
    }
    total_waiting_Time=total_waiting_Time/no_of_process;
    // Print All Values
    printf("Process\t\tArrival Time\tBurst Time\tCompletion Time\t\tTurn Around Time\tWaiting Time\n");
    for(int i=0;i<no_of_process;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",i+1,ArrivalTime[i],BurstTime[i], completion_time[i], turnAround_Time[i], waiting_Time[i]);
    }
    printf("\nAverage Turn Around Time = %f\n",total_turnAround_Time);
    printf("Average Waiting Time = %f",total_waiting_Time);
}

