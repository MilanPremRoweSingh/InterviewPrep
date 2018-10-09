///Problem Statement: https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for( int i = 0; i < height.size(); i++ )
        {
            for( int j = i; j < height.size(); j++ )
            {
                int minHeight = min(height[i], height[j]);
                int area = (j-i)*minHeight;
                maxArea = (area > maxArea) ? area : maxArea;
            }
        }
        return maxArea;
    }
};