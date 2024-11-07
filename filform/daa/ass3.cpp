//Write a program to solve a fractional Knapsack problem using a greedy method
#include<bits/stdc++.h>
using namespace std;



// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Comparator function to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate maximum profit for the fractional knapsack
void fractionalKnapsack(int W, vector<Item> items) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    int currentWeight = 0; // Current weight of knapsack
    double maxProfit = 0.0; // Resulting profit

    // Loop through all items
    int n=items.size();
    for (int i=0;i<n;i++) {
        // If adding the entire item doesn't exceed capacity
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            maxProfit += items[i].value;
        } else {
            // Take the fraction of the last item that fits in the knapsack
            int remainingWeight = W - currentWeight;
            maxProfit +=  remainingWeight* ((double)items[i].value / items[i].weight);
            break;
        }
    }

    cout<<maxProfit;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    
    cout << "Maximum profit in fractional knapsack: ";
    fractionalKnapsack(W, items);
    return 0;
}
