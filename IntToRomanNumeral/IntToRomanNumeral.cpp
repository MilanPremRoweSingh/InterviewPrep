// Problem Statement: https://leetcode.com/problems/integer-to-roman/description/
class Solution {
public:
    int decimalAtoms[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romanAtoms[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    string intToRoman(int num) {
        int idx = 0;
        string ret = "";
        while( num > 0 )
        {
            if( decimalAtoms[idx] <= num )
            {
                num -= decimalAtoms[idx];
                ret += romanAtoms[idx];
            }
            else
            {
                idx++;
            }
        }
        return ret;
    }
};