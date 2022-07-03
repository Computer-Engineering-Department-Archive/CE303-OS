#include "types.h"
#include "user.h"
#include "stat.h"

int main(void)
{
    setSchadulerStrategy(4);
    int pid;
    for (int i = 0; i < 10; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            printf(1, "fork error\n");
            exit();
        }
        if (pid == 0)
        {
            if (i < 2)
                settickets(15);                 
            if (i >= 2 && i < 4)
                settickets(17);
            if (i >= 4 && i < 6)
                settickets(19); 
            if (i >= 6 && i < 8)
                settickets(21);
            if (i >= 8 && i < 10)
                settickets(23);
            break;
        }
    }
    if (pid == 0)
    {
        pid = getpid();
        for (int j = 1; j < 25; j++)
        {
            printf(1, "%d : %d\n", pid, j);
        }
        int turnaroundTime = getTurnaroundTime(pid);
        int waitingTime = getWaitingTime(pid);
        int burstTime = getburstTime(pid);
        sleep(100 + 10 * pid); // to print in order
        printf(1, "PID : %d burstTime : %d\n", pid, burstTime);
        printf(1, "PID : %d Turnaround : %d\n", pid, turnaroundTime);
        printf(1, "PID : %d Waiting : %d\n", pid, waitingTime);
        exit();
    }
    else
    {
        int totalBurst = 0;
        int totalTurnaround = 0;
        int totalWaiting = 0;

        for (int i = 0; i < 10; i++)
        {
            pid = wait();
            int turnAroundTime = getTurnaroundTime(pid);
            int waitingTime = getWaitingTime(pid);
            int burstTime = getburstTime(pid);
            totalTurnaround += turnAroundTime;
            totalWaiting += waitingTime;
            totalBurst += burstTime;
        }
        int avgCBT = (totalBurst) / 10;
        int avgTAT = (totalTurnaround) / 10;
        int avgWT = (totalWaiting) / 10;
        printf(1, "Avg of CBT: %d\n", avgCBT);
        printf(1, "Avg of turnAroundTime: %d\n", avgTAT);
        printf(1, "Avg of WaitingTime: %d\n", avgWT);
        printf(0, "Parent Finished\n");
    }
    exit();
}