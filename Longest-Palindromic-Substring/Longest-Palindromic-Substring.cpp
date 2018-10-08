class Solution {
public:
    string longestPalindrome(string s) {
        vector<string> palindromes;
        vector<int> positions;
        
        if (s.size() <= 0){
            return "";
        }
            
        
        for( int i = 0; i < s.size(); i++ ){
            palindromes.push_back(string(&s[i],1));
            positions.push_back(i);
        }
        string maxPalindrome = palindromes[0];
        bool newPalindromeFound = false;
        do {
            newPalindromeFound = false;
            
            for( int i = 0; i < palindromes.size(); i++ ){
                string curr = palindromes[i];
                int idx = positions[i];

                // If the whole string is a palindrome, return it 
                if( palindromes[i].size() == s.size()  ){
                   return palindromes[i];
                }
                // If curr starts at the first position of the string, we try adding only the rightmost char
                else if( positions[i] == 0 ){
                   string attempt = curr + s[idx + curr.size()];
                   if( isPalindrome( attempt ) ){
                       palindromes[i] = attempt;
                       maxPalindrome = (attempt.size() > maxPalindrome.size()) ? attempt : maxPalindrome;
                       newPalindromeFound = true;
                   }
                    else {
                        palindromes.erase(palindromes.begin() + i);
                        positions.erase(positions.begin() + i);
                        i--;
                    }
                }
                // If curr ends at the last position of the string, we try adding only the leftmost char
                else if ( positions[i] + palindromes[i].size() >= s.size() ){
                    string attempt = s[idx - 1] +  curr;
                    if( isPalindrome( attempt ) ){
                       palindromes[i] = attempt;
                       maxPalindrome = (attempt.size() > maxPalindrome.size()) ? attempt : maxPalindrome;
                       positions[i] -= 1;
                       newPalindromeFound = true;
                   }
                    else {
                        palindromes.erase(palindromes.begin() + i);
                        positions.erase(positions.begin() + i);
                        i--;
                    }
                }
                // Otherwise try adding either or both
                else {
                    char left = s[idx-1];
                    char right = s[idx + curr.size()];
                    
                    if( left == right ){
                       palindromes[i] = left + curr + right;
                       maxPalindrome = (palindromes[i].size() > maxPalindrome.size()) ? palindromes[i] : maxPalindrome;
                       positions[i] -= 1;
                       newPalindromeFound = true;
                    }
                    //Note that if the last test fail then left cannot make a palindrome if right would and vice versa
                    else if( isPalindrome(left + curr ) ){
                       palindromes[i] = left + curr;
                       maxPalindrome = (palindromes[i].size() > maxPalindrome.size()) ? palindromes[i] : maxPalindrome;
                       positions[i] -= 1;
                       newPalindromeFound = true;
                    }
                    else if( isPalindrome( curr + right ) ){
                       palindromes[i] = curr + right;
                       maxPalindrome = (palindromes[i].size() > maxPalindrome.size()) ? palindromes[i] : maxPalindrome;
                       newPalindromeFound = true;
                    }
                    else {
                        palindromes.erase(palindromes.begin() + i);
                        positions.erase(positions.begin() + i);
                        i--;
                    }
                }
                
            } 
        } while( newPalindromeFound );
        return maxPalindrome;
    }
    
    bool isPalindrome( string s ){
        for( int i = 0; i <= s.size()/2; i++ ){
            if( s[i] != s[s.size()-i-1] )
            {
                return false;
            }
        }
        return true;
    }
};

