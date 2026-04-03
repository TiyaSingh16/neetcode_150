class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max1=0,left=0,right=(heights.size()-1);
        while(left<right){
            int area=min(heights[left],heights[right])*(right-left);
            max1=max(max1,area);
            if(heights[left]<=heights[right]) left++;
            else right--;
        }
        return max1;
    }
};
