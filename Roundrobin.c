#include <stdio.h> 
 
int main() { 
    int n, tq, time = 0, completed = 0;     int at[10], bt[10], rt[10];     int wt[10], tat[10], ct[10], resp[10];     int visited[10] = {0}; 
    float avg_wt = 0, avg_tat = 0, avg_resp = 0; 
 
    printf("Enter number of processes: ");     scanf("%d", &n); 
 
    for (int i = 0; i < n; i++) { 
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);         scanf("%d %d", &at[i], &bt[i]);         rt[i] = bt[i]; 
        resp[i] = -1;   // response time initialization 
    } 
 
    printf("Enter Time Quantum: ");     scanf("%d", &tq); 
 
    while (completed < n) { 
        int executed = 0; 
 
        for (int i = 0; i < n; i++) {             if (rt[i] > 0 && at[i] <= time) { 
                executed = 1; 
 
                // First response                 if (resp[i] == -1)                     resp[i] = time - at[i];                 if (rt[i] > tq) {                     time += tq;                     rt[i] -= tq;                 } else {                     time += rt[i];                     rt[i] = 0;                     ct[i] = time; 
                    completed++; 
                } 
            } 
        } 
 
        if (!executed) 
            time++;  // CPU idle 
    } 
 
    printf("\nProcess\tAT\tBT\tWT\tTAT\tRT\n"); 
 
    for (int i = 0; i < n; i++) {         tat[i] = ct[i] - at[i]; 
        wt[i] = tat[i] - bt[i]; 
 
        avg_wt += wt[i];         avg_tat += tat[i];         avg_resp += resp[i]; 
 
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n", 
               i + 1, at[i], bt[i], wt[i], tat[i], resp[i]); 
    } 
 
    avg_wt /= n;     avg_tat /= n; 
    avg_resp /= n; 
 
    printf("\nAverage Waiting Time     = %.2f", avg_wt);     printf("\nAverage Turnaround Time  = %.2f", avg_tat);     printf("\nAverage Response Time    = %.2f\n", avg_resp); 
 
    return 0; 
} 
