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




















