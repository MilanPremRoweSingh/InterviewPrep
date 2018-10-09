// Problem Description Here: https://leetcode.com/problems/regular-expression-matching/description/
class State {
public:
    State();
    using MapType = unordered_map<char, State>;
    shared_ptr<MapType> m_transitions;
};

class Solution {
public:
    
    bool isMatch(string s, string p) {
        if( ( s.size() == 0 && p.size() == 0 )  || p.size() == 0 )
        {
            return s.size() == 0;
        }
        
        if( p.size() > 1 )
        {
            if(p[1] == '*')
            {
                if( s.size() > 0 )
                {
                    if( s[0] == p[0] || p[0] == '.' )
                    {
                        if( isMatch(s.substr(1,s.size()-1), p ) )
                        {
                            return true;
                        }
                    }
                }
                return isMatch(s, p.substr(2,p.size()-2));
            }
        }
        
        if( s.size() > 0 )
        {
            if( s[0] == p[0] || p[0] == '.' )
                return isMatch(s.substr(1,s.size()-1), p.substr(1,p.size()-1) );
            else
                return false;
        }
        else
        {
            // Case where s==0 && p!= 0 && p is not at a * pattern
            return false;
        }
    }
    
};