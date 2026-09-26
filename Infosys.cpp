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

//More btter explanantion written 
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
