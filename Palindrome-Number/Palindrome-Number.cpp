// Problem Description Here: https://leetcode.com/problems/palindrome-number/description/
class Solution {
public:
    bool isPalindrome(int x) {
        return (reverse(x) == x) && (x >= 0)   ;
    }
    
    int reverse(int x) {
        int curr = x;
        int revX = 0;
        int signX = sign(x);  
        while( curr != 0 ){
            int digit = curr % (signX*10);
            curr = curr / 10;
            if (revX > INT_MAX/10 || (revX == INT_MAX / 10 && digit > 7)) return 0;
            if (revX < INT_MIN/10 || (revX == INT_MIN / 10 && digit < -8)) return 0;
            revX = revX*10 + digit;
        }
        return revX;
    }
    
    int sign( int x ){
        return (x< 0) ? -1 : 1;
    }
};