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

2.)
  
