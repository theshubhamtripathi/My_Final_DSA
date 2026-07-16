1. Core Concepts Memoization (Top-Down): Solving the problem by breaking it down from the main problem (n) towards the base cases (0 or 1), and storing the answers on the way down.
  Tabulation (Bottom-Up): Starting from the base cases (0 or 1) and building up the solution step-by-step using loops until you reach the target (n).
  Overlapping Subproblems: When a recursive program calculates the exact same subproblem again and again.
  The Goal of DP: We use a storage structure (like a 1D or 2D array) to save the results of overlapping subproblems so we can reuse them instantly in $O(1)$ time instead of recalculating them.💡 
  Dimension Rule: The number of dimensions of your DP array ($1\text{D}$, $2\text{D}$, etc.) directly depends on the number of changing parameters in your recursive function.2.
  The 3 Golden Steps of MemoizationWhenever you convert a normal recursive function into a Memoized DP function, strictly follow these 3 steps:
  Declare: Initialize a DP storage array (or vector) of size n + 1 inside main() and fill it entirely with -1 to represent unexplored states.
  Check: Right after your base cases, check if the subproblem has already been solved before: if(dp[n] != -1) return dp[n];.
  Store: Before returning your final recursive calculation, assign it directly into your DP array: return dp[n] = f(n-1) + f(n-2);.
    
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

The 3 Master Keywords (What the question asks)If you see these terms in a problem description, it is a $90\%$ guarantee that it can be modeled with Recursion, which you can then optimize using DP:
Optimization: "Find the Minimum cost...", "Find the Maximum profit...", "What is the longest path..."
  Counting: "Find the Total number of ways to reach...", "How many distinct combinations exist..."
  Checkability (True/False): "Is it possible to partition the array into two subsets with equal sum?"2. The Core Pattern: "
  Choice & Constraints"Keywords alone aren't enough; you must look at the structure of your decisions. You are dealing with a recursive/DP problem if you have:Multiple Choices at Each Step: At any given point, you have to choose between doing Option A, Option B, or Option C (e.g., in Climbing Stairs, you can take $1$ step or $2$ steps).
  Dependent Future Decisions: The choice you make right now changes what choices are allowed or optimal next.
  No Short-sighted Formula (Greedy Fails): If making the immediately "best-looking" choice right now ruins your chances later down the line, you cannot use a simple greedy algorithm. You must check all paths.
  3. The "Overlapping" Test (The Final Decider)To be absolutely sure recursion/DP applies, draw a tiny decision tree for a small input on a piece of scratch paper. Look closely at the branches.Are you solving the exact same branch more than once?If YES: It is an Overlapping Subproblem. This means Pure Recursion will work, and you can instantly boost it to DP using Memoization or Tabulation.
  If NO (all branches are completely unique, like generating permutations of a string): It is a Pure Recursion/Backtracking problem, and DP cannot optimize it.

class Solution {
public:

    int solve(int n,vector<int> &dp){
        if(n<0) return 0;
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};  

//The exact difeernece btwenn greedy and dp 
The most important difference is that greedy algorithms make a locally optimal choice at each step and never reconsider or backtrack, whereas dynamic programming (DP) solves overlapping subproblems, stores their results, and explores all possible combinations to guarantee a globally optimal solution.

//Frog jump with k distances 
whenevr u see total count or all possible ways make a map in your mid of creating and implementing recursion.
why greedy fails here :
1.) First if in the question it asks find all the steps and all possible ways it just hints us to do recursion
2.) Express the porblem in the terms of index 
3.) Do all the stuffs on that index 

Problem Statement: Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1..

//memoization solution
#include <bits/stdc++.h>
using namespace std;

int func(int idx, vector<int>& a, vector<int>& dp) {
    if (idx == 0) return 0;
    
    if (dp[idx] != -1) return dp[idx];
    
    int left = func(idx - 1, a, dp) + abs(a[idx] - a[idx - 1]);
    
    int right = INT_MAX;
    if (idx > 1) {
        right = func(idx - 2, a, dp) + abs(a[idx] - a[idx - 2]);
    }
    
    return dp[idx] = min(left, right);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> dp(n, -1);
    cout << func(n - 1, a, dp) << endl;
    return 0;
}

//Tabulation solution 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> dp(n, 0);
    dp[0] = 0;
    
    for (int i = 1; i < n; i++) {
        int left = dp[i - 1] + abs(a[i] - a[i - 1]);
        
        int right = INT_MAX;
        if (i > 1) {
            right = dp[i - 2] + abs(a[i] - a[i - 2]);
        }
        
        dp[i] = min(left, right);
    }
    
    cout << dp[n - 1] << endl;
    return 0;
}

//House robber 
class Solution {
public:
    int solve(int idx,vector<int>& dp,vector<int>& nums){
        if(idx == 0){
            return nums[0];
        }
        if(idx < 0) return 0;
        else if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(idx - 2,dp,nums);
        int leave = solve(idx-1,dp,nums);

        return dp[idx] = max(take,leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(n-1,dp,nums);
    }
};

// House RObber ||
class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx<0) return 0;
        else if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(idx-2,nums,dp);
        int leave = solve(idx-1,nums,dp);

        return dp[idx] = max(take,leave);
    }
    int rob(vector<int>& nums) {
        int n =  nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1,-1);
        vector<int> dp1(n+1,-1);
        vector<int> temp;
        vector<int> temp1;

        for(int i=0;i<n;i++){
            if(i != 0){
                temp.push_back(nums[i]);
            } 
            if(i != n-1){
                temp1.push_back(nums[i]);
            }
        }
        return max(solve(n-2,temp,dp),solve(n-2,temp1,dp1));
    }
};

// DP on 2-D Ninja Training 

see in some questions you have to consider some more parametres as we need one extra variable in this to tell us the last things so we took extra parameter here 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive helper function with 2D DP memory array
    int solve(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
        // Base Case: When we reach Day 0, we simply pick the maximum points possible
        if (day == 0) {
            int maxi = 0;
            for (int i = 0; i < 3; i++) {
                // We cannot pick the activity that matches 'last'
                if (i != last) {
                    maxi = max(maxi, points[0][i]);
                }
            }
            return maxi;
        }

        // If this exact day and last-activity restriction was calculated before, return it
        if (dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        // Loop through all 3 possible activities for the current day
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                // Points earned today + delegate the remaining days to the recursive call
                int activityPoints = points[day][i] + solve(day - 1, i, points, dp);
                maxi = max(maxi, activityPoints);
            }
        }

        // Save our maximum result in the 2D DP matrix before returning
        return dp[day][last] = maxi;
    }

    int ninjaTraining(int n, vector<vector<int>>& points) {
        // Create a 2D DP vector of size N x 4 (since 'last' can range from 0 to 3)
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        // Start from the last day (n-1) with a dummy restriction value of 3 (no restriction yet)
        return solve(n - 1, 3, points, dp);
    }
};

//Tabluation 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ninjaTraining(int n, vector<vector<int>>& points) {
        // Create a 2D DP matrix initialized to 0
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base Case Initialization: Fill out the values for Day 0 manually
        dp[0][0] = max(points[0][1], points[0][2]); // If activity 0 is restricted, pick max of 1 and 2
        dp[0][1] = max(points[0][0], points[0][2]); // If activity 1 is restricted, pick max of 0 and 2
        dp[0][2] = max(points[0][0], points[0][1]); // If activity 2 is restricted, pick max of 0 and 1
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]}); // If no restriction, pick max of all three

        // Loop through all remaining days from Day 1 up to Day N-1
        for (int day = 1; day < n; day++) {
            // Pre-calculate the result for every possible restriction state (0 to 3)
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;
                
                // Try performing each activity 'i' on the current day
                for (int i = 0; i < 3; i++) {
                    if (i != last) {
                        // Current day points + the best score from the previous day given restriction 'i'
                        int currentPoints = points[day][i] + dp[day - 1][i];
                        dp[day][last] = max(dp[day][last], currentPoints);
                    }
                }
            }
        }

        // The final maximum answer will be stored on the last day with no initial restriction (3)
        return dp[n - 1][3];
    }
};



  
