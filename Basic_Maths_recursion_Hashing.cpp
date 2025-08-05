//Extracting a digit 
// The modulus operator % computes the remainder when a number is divided by another number. When we perform N % 10 we get the last digit of the number N.
// Eg. N = 7789, then N%10 results in 9 which is the last digit.
// After extracting the last digit we need to remove the last digit as well which can be done via division operator.
// Eg. N = 7789 then N/10 results in 778, removing the last digit.


//  Counting a digit
//  Function to count the number
//  of digits in an integer 'n'.
// int countDigits(int n){
//     // Initialize a counter variable
//     // 'cnt' to store the count of digits.
//     int cnt = 0;
//     // While loop iterates until 'n'
//     // becomes 0 (no more digits left).
//     while(n > 0){
//         // Increment the counter
//         // for each digit encountered.
//         cnt = cnt + 1;
//         // Divide 'n' by 10 to
//         // remove the last digit.
//         n = n / 10;
//     }
//     // Return the
//     // count of digits.
//     return cnt;
// }

// Reverse a number
// class Solution {
// public:
//     int reverse(int x) {
//         int rev = 0;
//         while(x>0){     //if checking for negative use x!=0
//             int lastdigit = x%10;
//             rev = rev*10 + lastdigit;
//             x = x/10;
//         }
//         return rev;
//     }
// };

//Palindrome
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         int onumber = x;
//         int rev = 0;
//         while(x>0){                  //because -ve numbers are enever a palindrome so we are not inculding them 
//             int lastdigit = x%10;
//             if (rev > INT_MAX / 10) return false;
//             rev = rev*10 + lastdigit;
//             x = x/10;
//         }
//         if(onumber == rev){
//             return true;
//         }
//         else{
//             return false;
//         } 
//     }
// };

//these above 2 question taught us about the constaints involved 

//GCD HCF  gives the higheest common factor between 2 numbers (basic method)
// int GCD(int n1,int n2){
//   for(int i = min(n1,n2);i>0;i--){
//     if(n1%i == 0 && n2%i == 0){
//       return i;
//       break;
//     }
//    }
//   return 1;
//   }

//Euclidean GCD
//GCD(a,b) = GCD(a-b,b)
//we have to greater % smaller if one is zero then the other one is gcd 
// int GCD_EUCLID(int a, int b) {
//     while (a > 0 && b > 0) {
//         if (a > b) {
//             a = a % b;
//         } else {
//             b = b % a;
//         }
//     }
    
//     // After the loop, one of them will be 0
//     if (a == 0) {
//         return b;
//     } else {
//         return a;
//     }
// }
// its time complexity is log(min(a,b))

//Armsstrong number
//here we used 2 major concepts one is it chnages and num to string to_string(num).lenght(); it will give the lenghth or total number of digits in those numbers
//    return sum == num ? true : false;  ::  condition ? value_if_true : value_if_false   ? it is ternary operator which is mainly used for conditional things
// #include<iostream>
// bool ARMS(int n){
//     int original = n;
//     int k = to_string(n).length();
//     int sum = 0;
//     while(n>0){
//         int ld = n%10;
//         sum += pow(ld,k);
//         n /= 10;
//     }
//      return sum == original ? true : false;
// }

//Print all Divisors of a given Number 
//here the main logic is the anynumerber is divisible till its squareroot prime factors only means 36 will be divisible by all numbers and multiples which comes in 6
// so we will take the loop to square root n tak 
//we must use i*i instead of sqrt(i) because that one s more efficient 
//#include<iostream>
// #include<vector>
// #include<cmath>
// #include<algorithm>
// using namespace std;
// vector<int> divisor(int num){
//     vector<int> result;
//     for(int i=1;i*i<=num;i++){
//         if(num%i == 0){
//             result.push_back(i);
        
//             if(num/i != i){               //we are doing this thing beacsue suppose 36 is divisible by 6 then 36/6 = 6 then 6 will come for 2 times that is wrong we are inmeneting this logic to do n/2 = like for example 36/2 18 like that itna samajh le chutiye ab 
//             result.push_back(num/i);
//                 }
//             }
//     }
//     sort(result.begin(),result.end());
//     return result;
// }
// int main(){
//     int n;
//     cout<<"Enter the elemnt u want : ";
//     cin>>n;
//     vector<int> divisors = divisor(n);  //this line creates a variable to store the result returned by your divisor() function cause it is returning a vector only .
//     for(int i=0;i<divisors.size();i++){
//         cout<<divisors[i]<<" ";
//     }
//     return 0;
// }

//Prime
//Prime here one thing we have ti make sure that take all the number to sqrt of n so we dont have to cover the entire till n length we also make this code by bool flag for that you have to use break statement as well 
// #include<iostream>
// using namespace std;
// bool Prime(int n){
//     if(n==0 || n==1) return false;
//     if(n==2) return true;
//     for(int i=2;i*i<=n;i++){
//         if(n%i == 0){
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     cout<<"Enter your number : ";
//     int n;
//     cin>>n;
//     cout<<Prime(n);
//     return 0;
// }

//Recursion 
//it is a phenomenon when a function calls itself indefinitely until a specified condition is fulfilled.
//But, when there is no base condition given for a particular recursive function, it gets called indefinitely which results in a Stack Overflow i.e, exceeding the memory limit of the recursion stack and hence the program terminates giving a Segmentation Fault error.
//Printing number 0 to n 
// int count = 0;
// void func(){
//    if(count == 3 ) return;
//    print(count);
//    count++;
//    func();
// }
// main()
// {
//   print();
// }

//Printing names n time
// #include<bits/stdc++.h>
// using namespace std;
// void func(int i, int n){
//    // Base Condition.
//    if(i>n) return;
//    cout<<"Raj"<<endl;
//    // Function call to print till i increments.
//    func(i+1,n);
// }
// int main(){
//   // Here, let’s take the value of n to be 4.
//   int n = 4;
//   func(1,n);
//   return 0;
// }

//Printing numbrs from 1 to n
// #include<bits/stdc++.h>
// using namespace std;
// void func(int i, int n){
//    // Base Condition.
//    if(i>n) return;  
//    cout<<i<<endl;
//    // Function call to print i till i increments to n.
//    func(i+1,n);
// }
// int main(){
//   // Here, let’s take the value of n to be 4.
//   int n = 4;
//   func(1,n);
//   return 0;
// }  

//backtracking This is an alternative approach for printing the integers from N to 1 using recursion. In the previous approach, we used forward recursion but in this approach, we will be using backward recursion. The only change from the previous approach here will be that the print line would be kept after the function call inside the recursive function contrary to the previous approach. The function would be called for printing (i+1) integers and the ith integer would be printed.

//Printing numbers from n to 1 
// #include<bits/stdc++.h>
// using namespace std;
// void func(int i, int n){
//    // Base Condition.
//    if(i<1) return;
//    cout<<i<<endl;
//    // Function call to print i till i decrements to 1.
//    func(i-1,n);
// }

//Sum of till n intergers 
// #include<bits/stdc++.h>
// using namespace std;
// int func(int n){
//    // Base Condition.
//    if(n == 0)
//    {
//        return 0;
//    }
//    // Problem broken down into 2 parts and then combined.
//    return n + func(n-1);
// }

//Factorial
// #include <bits/stdc++.h>
// using namespace std;
// // Recursive function to calculate factorial of a number
// int factorial(int n) {
//     // Base case: factorial of 0 is 1
//     if (n == 0) {
//         return 1;
//     }
//     // Recursive case: n * factorial of (n-1)
//     return n * factorial(n - 1);
// }

//Reverse a array 
//First method using functions 
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main() {
//     int arr[] = {1,2,3,4,5};
//     int n = 5;
//     reverse(arr, arr + n);
//     for (int i = 0; i < n; i++) cout << arr[i] << " ";
//     // Output: 5 4 3 2 1
//     return 0;
// }
// Summary:
// reverse(arr, arr + n); reverses the entire array arr of size n.
// Works for vectors too: reverse(v.begin(), v.end());

//jab bhi void use karo function ke undar hi cout kardo and main ke andar direct function call 

//2nd method by swapping 
// #include<iostream>
// #include<algorithm>
// using namespace std;
// void Reverse(int arr[],int n){
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     int p1 = 0;   //first index
//     int pn = n-1; //last index 
//     while(p1<pn){
//         swap(arr[p1],arr[pn]);
//         p1++;
//         pn--;
//     }
//      for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
// int main(){
//     int n = 5;
//     int arr[] = {1,2,3,4,5};
//     Reverse(arr,n);
//     return 0;
// }

//Check wheteher a string is palindrome or not 





















































