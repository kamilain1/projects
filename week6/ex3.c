#include <stdio.h>
#include <stdlib.h>

void ProcessesSort(int **processes, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (processes[i][0] > processes[j][0]) {
                int *temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
}

void WaitingTime(int n, int *BT, int *WT, int quantum) {
    int BTcopy[n];
    for (int i = 0; i < n; i++)
        BTcopy[i] = BT[i];

    int t = 0;

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (BTcopy[i] > 0) {
                done = 0;
                if (BTcopy[i] > quantum) {
                    t += quantum;
                    BTcopy[i] -= quantum;
                } else {
                    t = t + BTcopy[i];
                    WT[i] = t - BT[i];
                    BTcopy[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void TurnaroundTime(int n, int *BT, int *WT, int *TAT) {
    for (int i = 0; i < n; i++)
        TAT[i] = BT[i] + WT[i];
}

void AvgTime(int *AT, int n, int *BT, int *CT, int quantum) {
    int wt[n], tat[n], WTsum = 0, TATsum = 0;

    WaitingTime(n, BT, wt, quantum);
    TurnaroundTime(n, BT, wt, tat);

    printf("P: \tAT   \tBT   \tCT   \tTAT   \tWT\n");

    for (int i = 0; i < n; i++) {
        WTsum = WTsum + wt[i];
        TATsum = TATsum + tat[i];
        printf("%d: \t%d   \t%d   \t%d   \t%d   \t%d\n", i + 1, AT[i], BT[i], CT[i], tat[i], wt[i]);
    }

    printf("Avg WT = %f\n", (float) WTsum / (float) n);
    printf("Avg TAT = %f\n", (float) TATsum / (float) n);

}

int main() {
    printf("Write the number of processes\n");
    int n;
    scanf("%d", &n);
    int **processes = malloc(sizeof(int *) * n);

    printf("Write arrival time and burst time for each process\n");
    for (int i = 0; i < n; i++) {
        processes[i] = malloc(sizeof(int) * 5);
        int ArrivalTime;
        int BurstTime;
        scanf("%d %d", &ArrivalTime, &BurstTime);
        processes[i][0] = ArrivalTime;
        processes[i][1] = BurstTime;
        processes[i][2] = 0;
        processes[i][3] = 0;
        processes[i][4] = 0;
    }
    ProcessesSort(processes, n);
    int AT[n];
    int BT[n];
    int CT[n];
    for (int i = 0; i < n; i++) {
        AT[i] = processes[i][0];
        BT[i] = processes[i][1];
    }

    for (int i = 0; i < n; i++) {
        if (BT[i] < processes[i][0]) BT[i] = processes[i][0];
        CT[i] = BT[i] + processes[i][1];
    }

    int quantum = 2;
    AvgTime(AT, n, BT, CT, quantum);
    return 0;
}