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

void BSort(int **processes, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (processes[i][1] > processes[j][1])
               /*if (processes[i][0] >= processes[j][0])*/ {
                    int *temp = processes[i];
                    processes[i] = processes[j];
                    processes[j] = temp;
                }
}

int CompletionTime(int *BT, int **processes, int i) {
    if (*BT < processes[i][0]) *BT = processes[i][0];
    int CT;
    CT = *BT + processes[i][1];
    processes[i][2] = CT;
    return CT;
}

int Turnaroundtime(int CT, int **processes, int i, double *TATsum) {
    int TAT;
    TAT = CT - processes[i][0];
    processes[i][3] = TAT;
    *TATsum = *TATsum + TAT;
    return TAT;
}

int WaitingTime(int TAT, int **processes, int i, double *WTsum, int *BT) {
    int WT;
    WT = TAT - processes[i][1];
    processes[i][4] = WT;
    *WTsum = *WTsum + WT;
    *BT = *BT + processes[i][1];
    return WT;
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
    BSort(processes, n);

    int BT = 0;
    double TATsum = 0;
    double WTsum = 0;

    for (int i = 0; i < n; i++) {
        int CT, TAT, WT;
        CT = CompletionTime(&BT, processes, i);
        TAT = Turnaroundtime(CT, processes, i, &TATsum);
        WT = WaitingTime(TAT, processes, i, &WTsum, &BT);
    }
    for (int i = 0; i < n; ++i) {
        printf("P%d(%d, %d): \tCT = %d \v\tTAT = %d \v\tWT = %d\n", i, processes[i][0], processes[i][1],
               processes[i][2], processes[i][3], processes[i][4]);
    }
    printf("Average TAT = %f\n", TATsum / n);
    printf("Average WT = %f\n", WTsum / n);

    return 0;
}