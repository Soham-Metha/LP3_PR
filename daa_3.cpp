#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100

int wt[MAX_N], val[MAX_N], n, W, best = 0;

void BB_knapsack(int i, int weight, int profit) {
    if (weight > W) return;

    if (i == n) {
        best = max(best, profit);
    } else {
        BB_knapsack(i + 1, weight + wt[i+1], profit + val[i+1]); /*Pick*/
        BB_knapsack(i + 1, weight, profit); /*Dont pick*/
    }
}

void DP_knapsack()
{
    vector<int> dp(W + 1, 0); // dp[weight] = max possible value

    for (int i = 0; i < n; i++) { // last item index
        for (int w = W; w >= wt[i]; w--) { // weight capacity
            dp[w] = max(/*Dont pick*/ dp[w], /*Pick*/ val[i] + dp[w-wt[i]]);
        }
    }

    return dp[W];
}

int main() {
    cout << "Enter knapsack capacity and item count: ";
    cin >> W >> n;
    assert(n <= MAX_N && "Choose a smaller 'n' value!");

    cout << "Enter weights & values of items:\n";
    for (int i = 0; i < n; i++) cin >> wt[i] >> val[i];

    cout << "Maximum value = " << DP_knapsack() << endl;

    BB_knapsack(0,0,0);
    cout << "\n BB & Maximum value = " << best << endl;

    return 0;
}

// TODO: B&B

/*
Enter knapsack capacity and item count: 50 3
Enter weights & values of items:
10 60
20 100
30 120
Maximum value = 220
*/