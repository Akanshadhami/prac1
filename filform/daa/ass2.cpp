//Implement job sequencing with deadlines using a greedy method.


#include<bits/stdc++.h>
using namespace std;


// Define a structure to represent a job
struct Job {
    int id;        // Job ID
    int deadline;  // Deadline of job
    int profit;    // Profit if job is completed before or on the deadline
};

// Comparator function to sort jobs in decreasing order of profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit job sequence
void jobSequencing(vector<Job> &jobs, int n) {
    // Sort all jobs according to decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Array to store the result of the job sequence (job IDs)
    vector<int> result(n, -1);

    // Keep track of free time slots
    vector<bool> slot(n, false);

    // Maximum profit accumulated
    int maxProfit = 0;

    // Iterate over all jobs
    for (int i = 0; i < jobs.size(); i++) {
        // Find a free slot for this job (starting from its deadline)
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            // If a free slot is found
            if (!slot[j]) {
                result[j] = jobs[i].id;   // Assign job ID to the slot
                slot[j] = true;           // Mark the slot as occupied
                maxProfit += jobs[i].profit; // Accumulate profit
                break;
            }
        }
    }

    // Display the selected jobs and the maximum profit
    cout << "Selected job sequence: ";
    for (int i = 0; i < n; i++) {
        if (result[i] != -1)
            cout <<"--> "<< "Job" << result[i] << " ";
    }
    cout << "\nMaximum Profit: " << maxProfit << endl;
}

int main() {
    int n; // Number of jobs
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job details (id, deadline, profit):\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Find the maximum number of slots available (maximum deadline)
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Call the job sequencing function
    jobSequencing(jobs, maxDeadline);

    return 0;
}
