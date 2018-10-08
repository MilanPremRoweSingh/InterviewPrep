// Problem Description Here: https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        if( s.size() < 1 || numRows < 1 )
        {
            return "";
        }
        
        if( numRows == 1)
        {
            return s;
        }
        
        vector<string> rows(numRows);
        string retStr = "";
        
        int idx = 0;
        int lenWritten = 0;
        while( lenWritten < s.size() )
        {
            int rowIdx = idx % numRows;
            int colIdx = idx / numRows;

            int colIdxInCurrCycle = colIdx % (numRows-1);
            if ( colIdxInCurrCycle == 0 ) { 
                rows[rowIdx] = rows[rowIdx] + s[lenWritten];
                lenWritten++;
                idx++;
            } 
            else
            {
                int rowToWriteIn = numRows - colIdxInCurrCycle-1;
                rows[rowToWriteIn] = rows[rowToWriteIn] + s[lenWritten];
                lenWritten++;
                idx += numRows;
            }
        }
        
        string retStr0 = "";
        
        for( int i = 0; i < numRows; i++ )
        {
            for( int j = 0; j < rows[i].size(); j++ ){
                retStr0 = retStr0 + rows[i][j]; 
            }
        }
        //retStr += rows[numRows-1];
        return retStr0;
    }
};