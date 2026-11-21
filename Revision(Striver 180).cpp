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
