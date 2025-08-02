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
//     vector<int> divisors = divisor(n);
//     for(int i=0;i<divisors.size();i++){
//         cout<<divisors[i]<<" ";
//     }
//     return 0;
// }






























