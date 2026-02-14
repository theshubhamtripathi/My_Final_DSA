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

//this only works when All numbers are positive


Optimal : 
    
