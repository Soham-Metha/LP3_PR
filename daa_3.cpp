#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, W;
    
    cout << "Enter knapsack capacity and item count: ";
    cin >> W >> n;

    int wt[n], val[n];
    vector<int> dp(W + 1, 0); // dp[weight] = max possible value

    cout << "Enter weights & values of items:\n";
    for (int i = 0; i < n; i++) cin >> wt[i] >> val[i];

    for (int i = 0; i < n; i++) { // last item index
        for (int w = W; w >= wt[i]; w--) { // weight capacity
            dp[w] = max(/*Dont pick*/ dp[w], /*Pick*/ val[i] + dp[w-wt[i]]);
        }
    }

    cout << "Maximum value = " << dp[W] << endl;

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