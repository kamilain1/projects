#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_processes;
    int n_resources;

    FILE *input = fopen("input_dl.txt", "r");
    FILE *output = fopen("output_dl.txt", "w");

    // FILE *input = fopen("./input_ok.txt", "r");
    // FILE *output = fopen("./output_ok.txt", "w");

    printf("Number of processes: ");
    scanf("%d", &n_processes);

    printf("Number of resource types: ");
    scanf("%d", &n_resources);

    int *E = malloc(sizeof(int) * n_resources);
    for (int i = 0; i < n_resources; i++)
        fscanf(input, "%d", &E[i]);

    int *A = malloc(sizeof(int) * n_resources);
    for (int i = 0; i < n_resources; i++)
        fscanf(input, "%d", &A[i]);

    int **C = malloc(sizeof(int *) * n_processes);
    for (int i = 0; i < n_processes; i++) {
        C[i] = malloc(sizeof(int) * n_resources);
        for (int j = 0; j < n_resources; j++) {
            fscanf(input, "%d", &C[i][j]);
        }
    }

    int **R = malloc(sizeof(int *) * n_processes);
    for (int i = 0; i < n_processes; i++) {
        R[i] = malloc(sizeof(int) * n_resources);
        for (int j = 0; j < n_resources; j++) {
            fscanf(input, "%d", &R[i][j]);
        }
    }

    int *F = malloc(sizeof(int) * n_processes);
    for (int i = 0; i < n_processes; i++)
        F[i] = 0;

    while (1) {
        int n_current = -1;
        for (int i = 0; i < n_processes; i++) {
            if (!F[i]) {
                int good = 1;
                for (int j = 0; j < n_resources; j++) {
                    if (R[i][j] > A[j])
                        good = 0;
                }
                if (good) {
                    n_current = i;
                    F[n_current] = 1;
                    break;
                }
            }
        }
        if (n_current == -1)
            break;
        else {
            for (int j = 0; j < n_resources; j++)
                A[j] = A[j] + C[n_current][j];
        }
    }

    int n_deadlocks = 0;
    for (int i = 0; i < n_processes; i++) {
        if (!F[i])
            n_deadlocks++;
    }

    if (n_deadlocks == 0)
        fprintf(output, "No deadlock is detected");
    else if (n_deadlocks == 1)
        fprintf(output, "1 process is deadlocked");
    else
        fprintf(output, "%d processes are deadlocked", n_deadlocks);

    return 0;
}