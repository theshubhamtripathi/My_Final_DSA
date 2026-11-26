 LC 169 
  //Brute Sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};

//Better using map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n  = nums.size();
        unordered_map<int,int> mp;
        for(auto it : nums){
            mp[it] ++;
        }
        int nn = n/2;
        for(auto it : mp){
            if(nn < it.second){
                return it.first;
            }
        }
        return -1;
    }
};

//Optimal using voting moore algo
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // This logic is called Moore's Voting Algorithm.
        // The idea is simple: if an element appears more than n/2 times, 
        // it will survive even if all other different elements cancel its votes.

        // first we will take 2 variables, one for count and one for the element itself
        int c = 0; 
        int el;    
        
        for(int i = 0; i < nums.size(); i++){
            // if count becomes 0, it means all the previous elements cancelled each other out.
            // so we make the current element our new candidate and give it 1 vote.
            if(c == 0){
                el = nums[i];
                c++;
            }
            // if we see the same element again, we support it and increase the count.
            else if(nums[i] == el){
                c++;
            }
            // if we see a different element, it fights our candidate and decreases the count by 1.
            else{
                c--;
            }
        }
        
        // since the majority element is there more than half the time, 
        // its count will never fully stay at 0. It will be our final 'el'.
        return el;
    }
};

LC 53 
//Brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
      //Trying out all possible ways all
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            for(int j=i;j<nums.size();j++){
                sum += nums[j];
                maxsum = max(maxsum,sum);
            }
        }
        return maxsum;
    }
};

//most optimal Kdane 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxsum  = max(maxsum,sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxsum;
    }
};

LC 229
//There is one small mathmatical intepretation i am getting suppose we have to n/x total majority elements like in question if it is given if any number is present more than n/3 times then it is majority elemnt so max majority element possible in that case is 2 similarly if n/4 then 3 n/2 then 1.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        int mini = n/3 + 1;
        for(auto it : nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.second >= mini){
                ans.push_back(it.first);
            }
            if(ans.size() >= 2){
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

LC 152
//optimal
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int suff = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){

            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

            pre *= nums[i];
            suff *= nums[n-i-1];

            ans = max(ans,max(pre,suff));
        }
        return ans;
    }
};

//Bonus 
Common Wealth Bank of Australia (OA question) suppose a n is given for example 2 and a 2d matrix is given 1 2 1st row and 2 3 2nd row so we have to find the min and max and then find the difference in between eg 1+2 = 3 absolute min 2 +3 = 5 abs difference between is 5-3 = 2
//My intutuion is sort indidvidual rows and coloums and then make a maxi add all the max elements and then make  a min and add all the minimun elemets 
#include <bits/stdc++.h>
using namespace std;
int main() {
    int maxi = 0;
    int mini = 0;
    vector<vector<int>> arr = {{1,2,3},{1,2,3},{1,2,3}};
    for(auto &it : arr){
        sort(it.begin(),it.end());
        maxi += it[arr.size() - 1];
        mini += it[0];
    }
    cout<<maxi - mini;
    return 0;
}

LC 75

