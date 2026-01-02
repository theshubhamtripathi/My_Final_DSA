// s.length() == s.size()   // always true both length and size same 

// char ch = 'a';
// Holds ONLY ONE character
// Uses single quotes ' '

// string s = "abc";
// Holds multiple characters
// Uses double quotes " "

// string sub = s.substr(start, length);
// string s = "abcdef";
// string sub = s.substr(2, 3);  // "cde"

//leetcode 961 2n array max element 
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        // int n = nums.size();
        // int chahiye = n/2;
        // unordered_map<int,int> mp;
        // for(auto it:nums){
        //     mp[it]++;
        // }
        // for(auto it:mp){
        //     int element = it.first;
        //     int freq = it.second;
        //     if(freq == chahiye){
        //         return element;
        //     }
        // }
        // return -1;

        // nums.back() It returns the value of the last element.
        // nums.end() Returns: iterator , Points to: after last element
        // nums.end() - 1 Returns: iterator to last element
        // *(nums.end() - 1) returns Value

        int n = nums.size();
        for(int i=2;i<n;i++){
            if(nums[i] == nums[i-1] || nums[i] == nums[i-2]){
                return nums[i];
            }
        }
        return nums.back();
    }
};
