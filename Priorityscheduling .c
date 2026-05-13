
#include <stdio.h> 
struct process {    
 int pid;     
int burst_time;     
int priority;    
 int waiting_time;     int turnaround_time; 
}; 
 
int main() {     int n; 
    struct process p[20];     
    float avg_wt = 0, avg_tat = 0; 
     printf("Enter number of processes: ");           scanf("%d", &n); 
for (int i = 0; i < n; i++) 
{        
 p[i].pid = i + 1;        
 printf("\nProcess %d", p[i].pid);        
 printf("\nBurst Time: ");       
  scanf("%d", &p[i].burst_time);        
 printf("Priority: ");         
scanf("%d", &p[i].priority); 
    } 
 
    // Sort processes by priority (lower number = higher priority)     for (int i = 0; i < n - 1; i++)
 {         
for (int j = i + 1; j < n; j++)
 {           
  if (p[i].priority > p[j].priority) 
{               
  struct process temp = p[i]; 
 p[i] = p[j];                 p[j] = temp; 
            } 
        } 
    } 
 
    // Waiting time calculation     p[0].waiting_time = 0;     for (int i = 1; i < n; i++) { 
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time; 
    } 
 
    // Turnaround time calculation     for (int i = 0; i < n; i++) { 
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;         avg_wt += p[i].waiting_time; 
        avg_tat += p[i].turnaround_time; 
    } 
 
    avg_wt /= n;     avg_tat /= n; 
 
    printf("\n\nPID\tBT\tPR\tWT\tTAT");     for (int i = 0; i < n; i++) { 
        printf("\n%d\t%d\t%d\t%d\t%d", 
               p[i].pid,                p[i].burst_time,                p[i].priority,                p[i].waiting_time,                p[i].turnaround_time); 
    } 
 
    printf("\n\nAverage Waiting Time = %.2f", avg_wt); 
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat); 
 
    return 0; 
} 
