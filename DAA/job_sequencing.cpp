#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Job {
    string id;     
    int deadline;  
    int profit;    
    
    Job(string jobId, int d, int p) {
        id = jobId;
        deadline = d;
        profit = p;
    }
};

bool compareJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

int findMaxDeadline(vector<Job>& jobs) {
    int maxDeadline = jobs[0].deadline;
    for(const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    return maxDeadline;
}

void scheduleJobs(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);
    
    int n = jobs.size();
    
    int maxDeadline = findMaxDeadline(jobs);
    
    vector<string> sequence(maxDeadline, "");
    vector<bool> slot(maxDeadline, false);
    
    int totalProfit = 0;
    int scheduledJobs = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = min(maxDeadline - 1, jobs[i].deadline - 1); j >= 0; j--) {
            if(!slot[j]) {
                sequence[j] = jobs[i].id;
                slot[j] = true;
                totalProfit += jobs[i].profit;
                scheduledJobs++;
                break;
            }
        }
    }
    
    cout << "\nScheduled Jobs: ";
    bool first = true;
    for(int i = 0; i < maxDeadline; i++) {
        if(!sequence[i].empty()) {
            if(!first) {
                cout << " -> "; 
            }
            cout << sequence[i];
            first = false;
        }
    }
    cout << "\nTotal Jobs Scheduled: " << scheduledJobs;
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        Job("J1", 2, 100),  
        Job("J2", 1, 50),   
        Job("J3", 2, 80),   
        Job("J4", 1, 75),   
        Job("J5", 3, 60)    
    };
    
    cout << "Job Sequencing with Deadlines";
    cout << "\n-----------------------------";
    
    scheduleJobs(jobs);
    
    return 0;
}