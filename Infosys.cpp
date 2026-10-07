Leetcode 75 Sort 0 1 2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //using dutch national flag algo
        //we will assign 3 varibale i j and k 
        //int his question we will have 4 regions first one in that from to low-1 will 0 then from low to mid -1 will be ones and then the unsorted part will come then finally we have the part in which from to n-1 we will have the high parts 

        //isme apan ko 3 hi numbe rke sayth kehnlna hai so uske hi according humlob apne if conditions de denge.

        //mainly humara mid hi move karega.
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

Prefix sum concepts in my language : 
basically in prefix sum as the name indidcates we have one array and we create a another array where the sum of each element of the 2nd array is the sum of all the elemenyts of it from previous
like {1,2,3,4,5} then the prefic sum array will be {1,3,6,10,15}

** basically prefix sum gives us the optimal solution and in this we basically do calculate a sum then we remove what is not needed.

Leetcode 1 Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //THis is brute force solution in which we are trying all the possible outcomes O(n^2)
        // vector<int> res;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i+1;j<n;j++){
        //         sum = nums[i] + nums[j];
        //         if(sum == target){
        //             res.push_back(i);
        //             res.push_back(j);
        //         }
        //     }
        // }
        // return res;

      In this solution we implemented 2 pointer approach after sorting like a type of binary search and we basically make pairs and saved evveryhting in indexes so after sorting there will not be any issue of index changing
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int sum = 0;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i] = {nums[i],i};
        }
        sort(v.begin(),v.end());
        while(i<j){
            sum = v[i].first + v[j].first;
            if(sum == target){
                return {v[i].second,v[j].second};
            }
            else if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }

  //Most optimal way was making froma hashmap and checking whether the complement of that is presnt or not 
  //See my approcah for this will be like making a ordered map and storing the things in such a way like first storing then taking complement target-that value which stored then chekcing in the map again if we have that then we will return the ans.

  class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; // Stores: number -> original index
        
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i]; // Take complement
            
            // Check if complement is ALREADY in the map
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i}; // Return stored index and current index
            }
            
            // Store current value and its index into map
            mp[nums[i]] = i;
        }
        
        return {};
    }
};
};

Java’s HashMap operates internally as an array of bucket nodes (Node<K,V>[] table) with a default initial capacity of 16 and a load factor of 0.75, triggering a doubling of array size and element rehashing whenever total stored entries exceed capacity * loadFactor.
When inserting or retrieving a key-value pair, Java first calls key.hashCode(), applies a supplemental bit-shifting function (h ^ (h >>> 16)) to distribute hash bits uniformly, and calculates the bucket index using the fast bitwise formula index = hash & (capacity - 1). 
When two distinct keys map to the exact same array index (a collision), Java handles it via separate chaining by appending entries to a singly linked list at that bucket, using equals() to identify the exact key. 
To prevent worst-case performance degradation from heavy collisions, Java 8+ converts a buckets linked list into a balanced Red-Black Tree whenever its length reaches 8 or more (and total capacity is at least 64), converting it back to a list if elements drop to 6 during resizing. 
Consequently, operations like put(), get(), and remove() run in $O(1)$ average time complexity and O(N) space complexity, while worst-case time complexity is capped at $O(\log N)$ in Java 8+ due to treeification (compared to $O(N)$ in older Java versions).


Leetcode 88 Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};

Leetcode 15 3 Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute by using 3 loops 
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        //now 3 steps carate a temp add it then sort then put that in the set
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        //store in ans
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

//optimal 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        //optimal in this we are sorting and using the concept of 2 pointer
        vector<vector<int>> ans;
        //TO implement 2 pointer we have to sort the complete array 
        sort(nums.begin(),nums.end());

        for(int i =0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1])continue;
            //Next 2 pointers
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] +nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};

//More better explanantion written 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        // 1. Sort to enable two-pointer traversal
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Skip duplicate values for 'i' to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;     // Left pointer
            int k = n - 1;     // Right pointer

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    k--; // Sum is too large -> shrink from the right
                } 
                else if (sum < 0) {
                    j++; // Sum is too small -> grow from the left
                } 
                else {
                    // Found a valid triplet!
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Move pointers inward
                    j++;
                    k--;

                    // Skip duplicate values for 'j' and 'k'
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};

Leetcode 49 Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp; // Stores: sorted_string -> list of original strings
        
        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            
            // 1. Sort the characters of 'temp' to create the unique key
            sort(temp.begin(), temp.end());
            
            // 2. Group the original string under its sorted key
            mp[temp].push_back(strs[i]);
        }
        
        // 3. Collect all grouped vectors from the map
        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

Leetcode 3 Longest Substring Without Repeating Characters
//Whenever you see a problem like substring and longest start thinking about sliding window and 2 pointer 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp; // Stores: character -> last seen index
        
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < n; right++) {
            char ch = s[right];
            
            // If character was seen inside the current window, jump left pointer
            if (mp.find(ch) != mp.end()) {
                left = max(left, mp[ch] + 1);
            }
            
            // Store/update the last seen index of current character
            mp[ch] = right;
            
            // Calculate length of current window
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

Pointer Structure: A Singly Linked List (SLL) node stores data and one pointer (next), allowing unidirectional traversal. A Doubly Linked List (DLL) node stores data and two pointers (next and prev), allowing bidirectional traversal.
Memory Overhead: SLL uses less memory per node (1 pointer). DLL requires extra memory per node to store the prev pointer (2 pointers).
Deletion & Predecessor Lookup: Deleting a given target node reference or inserting before it takes $O(1)$ time in DLL (via node->prev), but $O(N)$ time in SLL because SLL must traverse from the head to find the preceding node.
Use Cases: SLL is ideal when memory is constrained and access is purely forward (Stacks, simple Queues). DLL is ideal for fast middle deletions and backward navigation (LRU Cache, Deque, Browser Back/Forward history).

Leetcode 142. Linked List Cycle II
In this question we are looking for basically, first we will check if there is a loop by totortoise and hare we will do this then we will check if there is loop then we will again make a p pointer and if p == slow then return the p
else slow is not rqual to fast return null.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL) return NULL; //Means if my linked list is empty or the it onyl contains one element only.

        ListNode* slow = head;
        ListNode* fast = head;
        //intialise both pointer on the head

        //Now move fast and slow pointer of the pointer collide then there will be cycle else no

        //to see if fast dont go beyond the limit
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ //means cycle present
                break;
            }
        }

        if(slow != fast){ //if no cycle
            return NULL;
        }

        ListNode* p = head;
        while(slow != p){
            p = p->next;
            slow = slow->next;
        }
        return p; //when p == slow
    }
};

Leetcode 206 and 21

Reverse a Linked List 206
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};

Merge 2 sorted list Leetcode 21
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* r;
        if(list1->val < list2->val){
            r = list1;
            r->next = mergeTwoLists(list1->next,list2);
        }
        else{
            r = list2;
            r->next = mergeTwoLists(list1,list2->next);
        }
        return r;
    }
};

Leetcode 20 Valid parenthesis
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            // Rule 1: Push opening brackets
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } 
            // Rule 2: Handle closing brackets
            else {
                // Check A: If stack is empty when seeing a closing bracket, it's invalid
                if (st.empty()) return false;

                // Check B: Match with the top of stack
                if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                } else if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                } else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    // Mismatched bracket type (e.g., top is '(', current is ']')
                    return false; 
                }
            }
        }

        // Rule 3: Stack must be empty at the end
        return st.empty();
    }
};

//How to implement a stack(LIFO) using queue(FIFO) Leetcode 225
//In this we will follow a 3 step structure like first we will make sure 2 queues and in Q1 we will make that our main container from where we will return our ans we have to basically 
//make use of Q2 as a helper which helps us in maintaing Q1 and we will do that by using a 3 step method of 1.) we will copy every data of Q1 to Q2 then we will push that data to q1 then we will copy back evevyrhting again from q2
// to q1 and we will repeat the process.
class MyStack {
public:
    MyStack() {
        
    }
    //Created 2 queues
    queue<int> q1;
    queue<int> q2;

    void push(int x) {
        //In this loop we basically did we copy evevrything from q1 and pasted in q2 then we we push that specific element to q1 and then again copy everyhting from q2 to q1
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int ans  = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//Implement queue using stack Leetcode 232
These both questions are very similar as they both follow the similar 3 step method of copy pasting like we did previously 

class MyQueue {
public:

    stack<int> st1;
    stack<int> st2;
    //st1 will be our main and st2 will be our helper
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int ans = st1.top();
        st1.pop();
        return ans;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//These both are very similar and imp as well 

===================================================================
                  INFIX, PREFIX & POSTFIX CHEAT SHEET
===================================================================

1. DEFINITIONS
   • Infix   : Operator INSIDE operands     --> (A + B)  [Human standard]
   • Prefix  : Operator BEFORE operands     --> + A B    [Polish notation]
   • Postfix : Operator AFTER operands      --> A B +    [Reverse Polish]

2. WHY PREFIX & POSTFIX?
   • No parentheses needed to define order of operations.
   • Easy for computers to evaluate using a STACK data structure in O(N) time.

3. PAPER CONVERSION METHOD (Bracket-and-Move)
   Step 1: Fully parenthesize expression by priority.
   Step 2: Move operators inside their brackets.
           - For Postfix: Move to RIGHT of closing bracket.
           - For Prefix : Move to LEFT of opening bracket.
   Step 3: Remove all parentheses.

4. QUICK EXAMPLES
   -----------------------------------------------------------------
   Infix           | Postfix (Move Right) | Prefix (Move Left)
   -----------------------------------------------------------------
   A + B           | A B +                | + A B
   A + B * C       | A B C * +            | + A * B C
   (A + B) * C     | A B + C *            | * + A B C
   A * B + C / D   | A B * C D / +        | + * A B / C D
   -----------------------------------------------------------------

5. STACK RULE FOR INFIX TO POSTFIX
   • Operands  --> Output
   • '('       --> Push to Stack
   • ')'       --> Pop stack to output until '('
   • Operator  --> Pop higher/equal precedence operators from stack,
                   then push current operator.
===================================================================


Leetcode 33 search in a rotated sorted array (Binary search)

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // 1. Found target?
            if (nums[mid] == target) return mid;

            // 2. Is the LEFT half sorted?
            if (nums[low] <= nums[mid]) {
                // Check if target lies inside the left sorted range
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Target is in left half
                } else {
                    low = mid + 1;  // Target is in right half
                }
            } 
            // 3. Otherwise, the RIGHT half MUST be sorted!
            else {
                // Check if target lies inside the right sorted range
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Target is in right half
                } else {
                    high = mid - 1; // Target is in left half
                }
            }
        }

        return -1; // Target not found
    }
};

// Kdane algorithm Leetcode 53
we can also solve this question using our normal brute force approach one loop form i to another loop from i=j i am directly writing code for the most optimal one that is kdanes algorithm 
The main intuution of kdanes is to find sum of 2 numbers that is normla plus minus 
if evver subarray sum reaches negative then put that to zero (initialise with 0 when sum reaches 0)
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Tracks the sum of the current subarray we are expanding
        int currsum = 0;
        
        // Tracks the overall maximum sum found so far across all valid subarrays.
        // Initialized to INT_MIN so it works correctly even if all numbers are negative.
        int maxsum = INT_MIN;

        // Traverse through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Step 1: Add the current element to our running sum
            currsum += nums[i];

            // Step 2: Update the maximum sum seen so far.
            // MUST happen before resetting currsum so that all-negative arrays
            // capture the actual single maximum negative value instead of returning 0.
            maxsum = max(maxsum, currsum);

            // Step 3: If the running sum drops below 0, reset it back to 0.
            // Intuition: A negative prefix will only reduce the sum of any 
            // future subarray, so it's better to discard it and start fresh.
            if (currsum < 0) {
                currsum = 0;
            }
        }

        // Return the maximum subarray sum found
        return maxsum;
    }
};

Leetcode 560 Subarray sum equals k
//brute forces 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            //You have to reset the sum to check all the arrays
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                if(sum == k){
                    c++;
                }
            }
        }
        return c;
    }
};

//Optimal for this is unordered map and prefix sum
basically we use a prefic sum here that is the sum of all indexes of the array suppose the sum(i,j){sum of all the elements between i and j index} = sum[j] - sum[i-1] then you will get the sum of that sub part
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Step 1: Create a hash map to store <prefix_sum, frequency>
        // Key   = a running sum value we have seen so far
        // Value = how many times that running sum has occurred
        unordered_map<int, int> mp;

        // Base Case: A prefix sum of 0 has occurred ONCE before processing any elements.
        // Why? If sum equals k directly from index 0 (e.g., nums = [3], k = 3),
        // then (sum - k) = (3 - 3) = 0. We need mp[0] to be 1 so that count increments!
        mp[0] = 1;

        int sum = 0;   // Stores the running prefix sum from index 0 to i
        int count = 0; // Stores the total count of valid subarrays found

        // Step 2: Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Add current element to our running sum
            sum += nums[i];

            // Core Formula: If (sum - k) exists in our map, it means there exists
            // a previous prefix sum such that: (Current Sum) - (Old Prefix Sum) = k.
            int diff = sum - k;

            // Check if this required old prefix sum exists in our map
            if (mp.find(diff) != mp.end()) {
                // Add its frequency to our answer (there might be multiple starting points!)
                count += mp[diff];
            }

            // Step 3: Record the current running sum into the map for FUTURE elements to use
            mp[sum]++;
        }

        // Return total count of subarrays that sum up to k
        return count;
    }
};

Leetcode 56 Merge Intervals 
vec.back() == *(vec.end() - 1)  // This evaluates to true (5 == 5) like .end() return the pointer so you must deference it berfore giving the final result using *()
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};


Leetcode 78 Subsets
//Kabhi bhi jab jeewan me option dikhayi de toh recursion ke taraf jaa (take or leave approach)
//For typical dp and recursion question solve using tree diagram this makes the question more understanding and easy 

class Solution {
public:
    vector<vector<int>> result; //taking this as global so it can be used in both the functions 
    void solve(vector<int> &nums,vector<int> &temp,int i){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }

        //take 
        temp.push_back(nums[i]);
        solve(nums,temp,i+1);

        //dont take
        temp.pop_back();
        solve(nums,temp,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,temp,0);
        return result;
    }
};

Leetcode 90 Subsets ||
class Solution {
public:
    //Like in this question we have duplicates as well so we have to remove the duplicates as well so here we will use a while loop as well to remove the duplicates
    void solve(int i,vector<int>& nums,vector<int>& temp,vector<vector<int>>& result){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,result);

        // 2. Leave (exclude nums[i])
        // Skip all duplicate occurrences of nums[i] so we don't form identical subsets
        temp.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        
        solve(i + 1, nums, temp, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result; //2d vector to save all the answers
        vector<int> temp;
        sort(nums.begin(),nums.end()); //sort so that the adjacent elements stays together.......

        solve(0,nums,temp,result);
        return result;
    }
};

Leetcode 518 Coin exchnage ||
class Solution {
public:

    int solve(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount == 0) return 1;  //means we found one ans
        if(amount < 0 || i >= coins.size()) return 0;  //out of bound ho gaya no answer found
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = solve(i,amount-coins[i],coins,dp); //i isliye kyuki same coin le sakte hai dobara

        int skip = solve(i+1,amount,coins,dp);
        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        //as we can see here 2 parameters are chnagin one is amount and another one is index so we have to a 2d dp to memoizxe it 
        vector<vector<int>> dp(coins.size(),vector<int>(amount + 1 , -1));  //vector<vector<int>> dp( rows , vector<int>(cols, initial_value) );
        return solve(0,amount,coins,dp);
    }
};


Leetcode 322 Coin exchnage
//Greedy fails here so we use a dp on subsequnces approach 
// so we have to use try all the combos and take the combos that have the min coin not only the local optimal solution 

//if you have questions like infinite supply and multiple uses take keep the index same 
class Solution {
public:
    int solve(int i,vector<int> &coins,int amount,vector<vector<int>> &dp){
        if(amount == 0) return 0; //0 ho gayi hai total value
        if(amount < 0 || i >= coins.size()) return 1e9; //it represents in valid path
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = 1 + solve(i,coins,amount-coins[i],dp); //i wahi rahega beacuse we can take infinite coins and same coin again and again
        int skip = solve(i+1,coins,amount,dp);

        return dp[i][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount + 1,-1));

        int ans = solve(0,coins,amount,dp);
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};

Knight Travels
class Solution {
public:
    bool solve(vector<vector<int>> &grid,int r,int c,int n,int expV){
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expV){
            return false;  //grid[r][c] != expV this line is basically checking if we are going to all the steps one after another or not
        }
        if(expV == n*n - 1){
            return true;  //means it reached all the possible cases 
        }

        //All the 8 possible moves of knight main cheez yahi this iss code me total 8 steps ko count karna 

        int ans1 = solve(grid,r + 2,c-1,n,expV+1);
        int ans2 = solve(grid,r + 2,c+1,n,expV+1);
        int ans3 = solve(grid,r - 2,c-1,n,expV+1);
        int ans4 = solve(grid,r - 2,c+1,n,expV+1);
        int ans5 = solve(grid,r + 1,c-2,n,expV+1);
        int ans6 = solve(grid,r - 1,c-2,n,expV+1);
        int ans7 = solve(grid,r + 1,c+2,n,expV+1);
        int ans8 = solve(grid,r - 1,c+2,n,expV+1);

        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;

    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return solve(grid,0,0,grid.size(),0);
    }
};


Trappin rain water 


