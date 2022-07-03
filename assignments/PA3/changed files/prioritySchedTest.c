#include "types.h"
#include "user.h"
#include "stat.h"

int main(void)
{
    setSchadulerStrategy(2);
    int i = 0;
    int pid;
    for (i = 0; i < 30; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            printf(1, "EREOR\n");
            exit();
        }
        if (pid == 0)
        {
            pid = getpid();
            if (i < 5)
                setPriority(6);
            else if (i < 10 && i > 4)
                setPriority(5);
            else if (i < 15 && i > 9)
                setPriority(4);
            else if (i < 20 && i > 14)
                setPriority(3);
            else if (i < 25 && i > 19)
                setPriority(2);
            else if (i < 30 && i > 24)
                setPriority(1);

            for (int j = 1; j < 25; j++)
                printf(1, "%d : %d\n", pid, j);

            int turnaroundTime = getTurnaroundTime(pid);
            int waitingTime = getWaitingTime(pid);
            int burstTime = getburstTime(pid);
            sleep(2000 + 10 * pid); // to print in order
            printf(1, "PID : %d burstTime : %d\n", pid, burstTime);
            printf(1, "PID : %d Turnaround : %d\n", pid, turnaroundTime);
            printf(1, "PID : %d Waiting : %d\n", pid, waitingTime);
            exit();
        }
    }

    if (pid != 0)
    {
        setPriority(1);
        int classifiedTotalBurst[6];
        int classifiedTotalTurnaround[6];
        int classifiedTotalWaiting[6];

        int totalBurst = 0;
        int totalTurnaround = 0;
        int totalWaiting = 0;

        for (int i = 0; i < 30; i++)
        {
            pid = wait();
            int priority = getPriority(pid) - 1;
            int burstTime = getburstTime(pid);
            int turnAroundTime = getTurnaroundTime(pid);
            int waitingTime = getWaitingTime(pid);
            classifiedTotalBurst[priority] += burstTime;
            classifiedTotalTurnaround[priority] += turnAroundTime;
            classifiedTotalWaiting[priority] += waitingTime;
            totalBurst += burstTime;
            totalTurnaround += turnAroundTime;
            totalWaiting += waitingTime;
        }

        for (int i = 0; i < 6; i++)
        {
            int avgCBT = (classifiedTotalBurst[i]) / 5;
            int avgTAT = (classifiedTotalTurnaround[i]) / 5;
            int avgWT = (classifiedTotalWaiting[i]) / 5;
            printf(2, "Class[%d]_Avg of CBT: %d\n", i + 1, avgCBT);
            printf(2, "Class[%d]_Avg of turnAroundTime: %d\n", i + 1, avgTAT);
            printf(2, "Class[%d]_Avg of WaitingTime: %d\n", i + 1, avgWT);
        }

        int avgCBT = (totalBurst) / 30;
        int avgTAT = (totalTurnaround) / 30;
        int avgWT = (totalWaiting) / 30;
        printf(1, "TOTAL_Avg of CBT: %d\n", avgCBT);
        printf(1, "TOTAL_Avg of turnAroundTime: %d\n", avgTAT);
        printf(1, "TOTAL_Avg of WaitingTime: %d\n", avgWT);
        printf(0, "Parent Finished\n");
        exit();
    }
}