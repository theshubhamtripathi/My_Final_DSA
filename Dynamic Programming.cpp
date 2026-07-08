1. Core Concepts Memoization (Top-Down): Solving the problem by breaking it down from the main problem (n) towards the base cases (0 or 1), and storing the answers on the way down.
  Tabulation (Bottom-Up): Starting from the base cases (0 or 1) and building up the solution step-by-step using loops until you reach the target (n).
  Overlapping Subproblems: When a recursive program calculates the exact same subproblem again and again.
  The Goal of DP: We use a storage structure (like a 1D or 2D array) to save the results of overlapping subproblems so we can reuse them instantly in $O(1)$ time instead of recalculating them.💡 
  Dimension Rule: The number of dimensions of your DP array ($1\text{D}$, $2\text{D}$, etc.) directly depends on the number of changing parameters in your recursive function.2.
  The 3 Golden Steps of MemoizationWhenever you convert a normal recursive function into a Memoized DP function, strictly follow these 3 steps:
  Declare: Initialize a DP storage array (or vector) of size n + 1 inside main() and fill it entirely with -1 to represent unexplored states.
  Check: Right after your base cases, check if the subproblem has already been solved before: if(dp[n] != -1) return dp[n];.
  Store: Before returning your final recursive calculation, assign it directly into your DP array: return dp[n] = f(n-1) + f(n-2);.3. 
  Code Implementation: Fibonacci SequenceC++
#include <bits/stdc++.h>
using namespace std;

// Memoization Function (Top-Down Approach)
int f(int n, vector<int> &dp) {
    // 1. Regular Base Case
    if (n <= 1) return n;
    
    // 2. STEP 2 OF MEMOIZATION: Check if already calculated
    if (dp[n] != -1) return dp[n];

    // 3. STEP 3 OF MEMOIZATION: Store the result while returning
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int main() {
    int n;
    cin >> n;

    // 4. STEP 1 OF MEMOIZATION: Declare a DP array of size n+1 initialized to -1
    vector<int> dp(n + 1, -1);
    
    cout << f(n, dp) << endl;
    return 0;
}

//In tabulation we have to go from base case to answer(Bottom up) in memoization we go from top to bottom(top to bottom)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Handle small edge cases immediately
    if (n <= 1) {
        cout << n << endl;
        return 0;
    }

    // STEP 1: Declare a DP array of size n+1
    vector<int> dp(n + 1);

    // STEP 2: Initialize known base cases
    dp[0] = 0;
    dp[1] = 1;

    // STEP 3: Iterate from 2 to n to build the solution bottom-up
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // The final answer is sitting right at index n
    cout << dp[n] << endl;

    return 0;
}
