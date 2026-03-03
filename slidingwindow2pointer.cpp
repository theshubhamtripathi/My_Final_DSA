//leetcode 67 thoery neeche hai 
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size()-1;
        int m = b.size()-1;
        string ans = "";
        int sum = 0;
        int carry = 0;

        while(m>=0 || n>=0){
            sum = carry;
            if(n>=0){
                sum += a[n] - '0';   //this will convert into integer value 
                n--;
            }
            if(m>=0){
                sum += b[m] - '0';
                m--;
            }

            ans.push_back((sum%2==0) ? '0' : '1');
            carry = (sum>1) ? 1 : 0; //it means if sum is greter than 1 then 1 else 0
        }
    if(carry > 0){
            ans.push_back('1');
        }
    reverse(ans.begin(),ans.end());    
    return ans;
    }
};

1.) Constant Window 


Next Window Sum =
Previous Window Sum
- Element going out
+ Element coming in



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> a = {1,2,3,4,5,6};
    int k = 4;
    int n = a.size();

    int sum = 0;
    int l = 0;
    int r = k - 1;

    // Step 1: calculate first window sum
    for(int i = l; i <= r; i++){
        sum += a[i];
    }

    int maxs = sum;   // important

    // Step 2: slide the window
    while(r < n - 1){
        sum = sum - a[l];   // remove left element
        l++;

        r++;
        sum = sum + a[r];   // add new right element

        maxs = max(maxs, sum);
    }

    cout << maxs;
}

2.)longest subarray and substring with sum <= k in this type of problem we follow the pattern of brute better and optimal 

brute : in this we have to generate all the subarray tc O(n^2) 

#include<bits/stdc++.h>
int main(){
    vector<int> a = {1,2,3,4,5,6,7,8};
    int maxlen = 0;
    int n = a.size();
    int k = 15;
    //generate all subarrays
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];
            if(sum<=k){
                maxlen = max(maxlen,j-i+1);
            }
            else{
                break;  // works only for positive numbers if array consist of negative number then dont use this 
            }
        }
    }
    cout<<maxlen;
    return 0;
}

better : in better approach we will start with the window size of 1 and and we will use the concept of expand and shrink as we know we have two pointer in this 
l for the left most part and r for the right most part so for expanding we will chnage the r(increase) and for shrink we will change the l(dercrease) 


lenght at any specific position will be : r-l+1 //j-i+1

#include<bits/stdc++.h>
int main(){
    vector<int> a = {1,2,3,4,5,5,6,7};
    int n = a.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int k = 15;
    int maxlen = 0;
    while(r<n){
        sum += a[r];  //expand window
        while(sum>k){
            sum -= a[l];  //shrink window
            l++;
        }
        if(sum<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    cout<<maxlen;
    return 0;
}

tc = O(n+n)     
//this only works when All numbers are positive


Optimal : tc = O(n)
#include<bits/stdc++.h>
int main(){
    vector<int> a = {1,2,3,4,5,5,6,7};
    int n = a.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int k = 15;
    int maxlen = 0;
    while(r<n){
        sum += a[r];  //expand window
        if(sum>k){   //just chnage while to if 
            sum -= a[l];  //shrink window
            l++;
        }
        if(sum<=k){
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    cout<<maxlen;
    return 0;
}


3.) no of subarrays where some condition will be given
to solve this we have to do 2 things ro approaches we have to follow 
1.)no of subarrays whose sum <= k substract it with no of subarrays whose sum <= k-1

4.) finding the shortest or min winsow where any condition is given 
we will shink till the lowest possible the shortest we will get we will return it 

//leetcode 190 ptod
class Solution {
public:
    int reverseBits(int n) {
        if (n == 0){
            return 0;
        }
        int result = 0;
        for(int i=0;i<32;i++){
            result <<= 1; //leftshift by 1. 
            result = ((n&1)|result); //(n&1) tells the last digit of n then add it to the result
            n >>= 1; //as the digit is added move the digit to the right
        }
        return result;
    }
};    
    

//leetcode 693 ptod
class Solution {
public:
    bool hasAlternatingBits(int n) {
        //approach 1 
        //in c++ we have one method known as bitset which is 32 bit conainer and it stores the n as binary for implementing this method we alos have to find highest set bit which is equal to log2(n) till there our loop will go 
        // bitset<32> b(n);
        // int bits = log2(n);
        // for(int i=0;i<bits;i++){
        //     if(b[i] == b[i+1]) return false;
        // }
        // return true;

        //approach 2
        //in this we have just play with n%2 to get the bits and n/2 to move to next 
            // int currbit = n%2;
            // n /= 2;

            // while(n>0){
            //     if(currbit == n%2){
            //         return false;
            //     }
            //     currbit = n%2;
            //     n /= 2;
            // }
            // return false;


        //approach 3
        //for this approach we will do if we take xor operation that means different pe 1 and same me zero n ^ (n>>1) left shift ya right shift ye >> iske muh dekh ke socha karo then find the number of set bits in that wo (result)&(result++) if it comes == 0 then we have all set bits then the result is true else false we will use unsigned int to know the out of range problem 

        unsigned int result = n ^ (n>>1);
        return (result&(result+1))==0;


    }
};

//leetcode 1423 O(k^2)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //my attempt
        // int n = cardPoints.size();
        // int l = 0;
        // int r = k-1;
        // int sum = 0;
        // int maxsum = 0;

        // for(int i=l;i<=r;i++){
        //     sum += cardPoints[i];
        // }
        // maxsum = sum;
        // while(r<n){
        //     sum -= cardPoints[l];
        //     l++;
        //     r++;
        //     sum += cardPoints[r];
        //     maxsum = max(maxsum,sum);
        // }
        // return maxsum;

        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;

        for(int i=0;i<k;i++){
            lsum += cardPoints[i];
        }
        maxsum = lsum;
        int rindex = n-1;
        for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;
            maxsum = max(maxsum,lsum+rsum);
        }
        return maxsum;
    }
};

This problem is same as:
Remove a subarray of size n-k with minimum sum
Because picking k from ends = removing middle.

What is __builtin_popcount?
👉 It counts how many 1-bits are present in a number.
    
//leetcode 3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //approach 1 order of n^2 generation all the substrings
        // int n = s.size();
        // int maxlen = 0;
        // for(int i=0;i<n;i++){
        //     vector<int> hash(256,0); //we have to reset it every time thats why here 
        //     for(int j=i;j<n;j++){
        //         if(hash[s[j]] == 1) break;
        //         maxlen = max(j-i+1,maxlen);
        //         hash[s[j]] = 1;
        //     }
        // }
        // return maxlen;

//in this appraoch we are making it do in O(n) complexity as we have to just consider a empty window and we will keep of shirnking and expanding it based on the conditions given

    int l = 0;
    int r = 0;
    int maxl = 0;
    vector<int> hash(256,-1);
    int n = s.size();
    while(r<n){
        if(hash[s[r]] != -1)/*means element is present*/{
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
        }
        maxl = max(maxl,r-l+1);
        hash[s[r]] = r;  //👉 “Remember where this character appeared last.”
        r++;
        }
        return maxl;
    }
// hash[s[r]] >= l
// Because character may appear outside current window.

// Example:
// Window = [l=3 ... r]
// Character last appeared at index 1

// 👉 That repeat does NOT matter.
// So we only move l if repeat is inside current window.
    
};
    


//leetcode 1356 ptod
class Solution {
public:

    int firstbit(int n){
        int c = 0;
        while(n>0){
            c += n & 1;
            n >>= 1;
        }
        return c;
    }

    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int &a,int &b){ //we use & here to get the reference for the function 
            int ca = firstbit(a); //count a counts the one bits
            int cb = firstbit(b);

            if(ca == cb) return a<b;
            return ca<cb;
        };
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};

//leetcode 1404
class Solution {
public:

    // Function to add 1 to a binary string
    void addOne(string &s) {
        int i = s.size() - 1;  // Start from last index
        
        // Handle carry while bit is '1'
        while (i >= 0 && s[i] == '1') {
            s[i] = '0';       // 1 + 1 = 0 (carry continues)
            i--;
        }

        if (i >= 0) {
            // Found a '0', just make it '1'
            s[i] = '1';
        } else {
            // All bits were '1'
            // Example: 111 → 1000
            s = '1' + s;
        }
    }

    int numSteps(string s) {
        int count = 0;

        // Continue until string becomes "1"
        while (s != "1") {

            if (s.back() == '0') {
                // If even → divide by 2
                // Removing last bit is same as dividing by 2
                s.pop_back();
            }
            else {
                // If odd → add 1
                addOne(s);
            }

            count++;
        }

        return count;
    }
};


//leetcode 1004
//brute
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //we can convert this question into find the max subarray with most k zeros means both are doing the same thing  
        int n = nums.size();
        int maxl = 0;
        for(int i=0;i<n;i++){
            int zero = 0;
            for(int j=i;j<n;j++){
                if(nums[j] == 0){
                    zero++;
                }
                if(zero<=k){
                    maxl = max(maxl,j-i+1);
                }
                else{
                    break;
                }
            }
        }
        return maxl;
    }
};

//better
        int r = 0;
        int l = 0;
        int maxl = 0;
        int n = nums.size();
        int zero = 0;

        while(r<n){
            if(nums[r] == 0){
                zero++;
            }
            while(zero>k){
                if(nums[l] == 0){
                    zero--;
                }
                l++; // ✅ move left no matter what
            }
            if(zero<=k){
                maxl = max(maxl,r-l+1);
            }
            r++;
        }
        return maxl;

//optimal
        int r = 0;
        int l = 0;
        int maxl = 0;
        int n = nums.size();
        int zero = 0;

        while(r<n){
            if(nums[r] == 0){
                zero++;
            }
            if(zero>k){
                if(nums[l] == 0){
                    zero--;
                }
                l++; // ✅ move left no matter what
            }
            if(zero<=k){
                maxl = max(maxl,r-l+1);
            }
            r++;
        }
        return maxl;

With while

You guarantee:
At every iteration:
Window is valid (zero ≤ k)

With if

You allow:
Window may be invalid briefly
But next iteration it corrects itself


//leetcode 424
//as this is very similar to consecutive one problem we done just before we have to see in this the max occurence of the letter which is coming the most no of time 

class Solution {
public:
    int characterReplacement(string s, int k) {
        //brute force
        //we can find the max by len-maxf
        int n = s.size();
        int maxl = 0;
        for(int i=0;i<n;i++){
            vector<int> hash(26,0);
            int maxf = 0;
            int changes = 0;
            for(int j=i;j<n;j++){
                hash[s[j]-'A']++;
                maxf = max(maxf,hash[s[j]-'A']);
                changes = (j-i+1) - maxf;

                if(changes<=k){
                    maxl = max(j-i+1,maxl);
                }
                else{
                    break;
                }
            }
        }
        return maxl;
    }
};

//better
//better
        int r = 0;
        int l = 0;
        int maxf = 0;
        int maxl = 0;
        vector<int> hash(26,0);
        int n = s.size();
        while(r<n){
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);
            while((r-l+1)-maxf>k){
                hash[s[l]-'A']--;
                l++;
                maxf = 0;
                for(int i=0;i<26;i++){
                    maxf = max(maxf,hash[i]);
                }
            }
            if((r-l+1)-maxf<=k){
                maxl = max(maxl,r-l+1);
            }
            r++;
        }
        return maxl;

        //optimal
        class Solution {
public:
    int characterReplacement(string s, int k) {

        int l = 0;
        int maxl = 0;
        int maxf = 0;
        vector<int> hash(26, 0);

        for(int r = 0; r < s.size(); r++) {

            hash[s[r] - 'A']++;

            // only increase maxf
            maxf = max(maxf, hash[s[r] - 'A']);

            // shrink window if invalid
            while((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxl = max(maxl, r - l + 1);
        }

        return maxl;
    }
};

//leetcode 762
class Solution {
public:
    bool isprime(int n){
        if(n <= 1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }

    int setbits(int n){
    int count = 0;
    while(n){
        count += (n & 1);
        n >>= 1;
        }
        return count;
    }

    int countPrimeSetBits(int left, int right) {
        int r = 0;
        for(int i=left;i<=right;i++){
            //set bits find we can use __builtin_popcount();
            if(isprime(setbits(i))){
                r++;
            }
        }
        return r;
    }
};

//leetcode 930
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //brute
        int n = nums.size();
        int count = 0;
        //generate all subraays
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum == goal){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //better
        

    }
};


class Solution {
public:

    int atMost(vector<int>& nums, int goal){
        if(goal < 0) return 0;

        int l = 0, sum = 0, count = 0;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        //generate all subraays
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += nums[j];
        //         if(sum == goal){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // //optimal
        // int l = 0;
        // int r = 0;
        // int sum = 0;
        // if(goal < 0) return 0;
        // while(r<nums.size()){
        //     sum += nums[r];
        //     while(sum>goal){
        //         sum -= nums[l];
        //         l++;
        //     }
        //     count += r-l+1;
        //     r++;
        // }
        // return count;

        return atMost(nums, goal) - atMost(nums, goal - 1); //because we need for only goal not less then equal to goal
    }
};


//leetcode 1248
class Solution {
public:
    int atmost(vector<int> &nums,int k){
        if(k<0) return 0;
        int l=0;
        int r=0;
        int sum=0;
        int count=0;
        while(r<nums.size()){
            sum += nums[r]%2;
            while(sum>k){
                sum -= nums[l]%2;
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        //lets generate all the subarrays
        // for(int i=0;i<n;i++){
        //     int oddc = 0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]%2 != 0){
        //             oddc++;
        //         }
        //         if(oddc == k){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //better we can set the l=0 and r=k-1 if we will find the the excat things we will expand the window
        return atmost(nums,k)-atmost(nums,k-1);
    }
};

//leetcode 1358

