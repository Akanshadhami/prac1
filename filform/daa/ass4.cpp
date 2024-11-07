//Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and 
//bound strategy

#include<bits/stdc++.h>
using namespace std;


int knapsackDP(int W, vector<int> &weights, vector<int> &values, int n) {
    // DP table to store the maximum profit for each weight and item combination
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W]; // The maximum profit for the given knapsack capacity
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<int> weights(n), values(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> weights[i] >> values[i];
    }

    int maxProfit = knapsackDP(W, weights, values, n);
    cout << "Maximum profit in 0-1 knapsack (DP): " << maxProfit << endl;

    return 0;
}

