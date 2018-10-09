// Problem Statement: https://leetcode.com/problems/valid-number/description/

class Solution {
public:
    bool isNumber(string s) {
        bool intReq = true;
        bool decimalAllowed = true;
        bool termComplete = false;
        bool signAllowed = true;
        bool numberStarted = false;
        bool expSeen = false;
        
        for( int i = 0; i < s.size(); i++ )
        {
            if( termComplete )
            {
                // If we have a complete number and we receive anything but whitespace -> reject
                if( s[i] != ' ' )
                {
                    return false;
                }
            }
            else
            {
                if( s[i] >= '0' && s[i] <= '9' )
                {
                    intReq = false;
                    numberStarted = true;  
                    signAllowed = false;
                }
                // If we get a sign symbol any time after number starts -> reject
                else if( !signAllowed && (s[i] == '-' || s[i] == '+') )
                {
                    return false;
                }
                else if ( s[i] == '-' || s[i] == '+' )
                {
                    signAllowed = false;
                    numberStarted = true;
                }
                //Whitespace after number starts
                else if( numberStarted && s[i] == ' ' )
                {
                    // If we receive whitespace where we want a number -> reject 
                    if( intReq ) return false;
                    
                    termComplete = true;
                }
                // If we are in a state which does not allow decimals and we receive one -> reject
                else if( !decimalAllowed && s[i] == '.' )
                {
                    return false;
                }
                // Only one decimal is allowed in any number
                else if( decimalAllowed && s[i] == '.' )
                {
                    decimalAllowed = false;
                    numberStarted = true;    
                    signAllowed = false;
                }
                // If we receive e, we must have a number already and no decimals allowed 
                else if( s[i] == 'e' )
                {
                    if( intReq ) return false;
                    if( expSeen ) return false;
                    decimalAllowed = false;
                    intReq = true;
                    expSeen = true;
                    signAllowed = true;
                }
                else if( s[i] != ' ')
                {
                    return false;
                }
                
            }
        }
        
        return !intReq;
    }
};