//Write a program to generate binomial coefficients using dynamic programming.

#include<bits/stdc++.h>
using namespace std;


// Function to calculate binomial coefficient C(n, k) using DP
int binomialCoefficient(int n, int k) {
    // Create a 2D vector to store binomial coefficients
    vector<vector<int>> C(n + 1, vector<int>(k + 1, 0));

    // Fill the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            // Base case: C(n, 0) = C(n, n) = 1
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                // Use the recurrence relation
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    // Return the result C(n, k)
    return C[n][k];
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    int result = binomialCoefficient(n, k);
    cout << "Binomial Coefficient C(" << n << ", " << k << ") = " << result << endl;

    return 0;
}
