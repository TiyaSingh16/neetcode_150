class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(),0);
        vector<int> right(heights.size(),0);
        stack<int> stack;
        int ans=0,n=heights.size(),area=0;
        //right smaller nearest:
        for(int i=heights.size()-1;i>=0;i--){
            while(!stack.empty()&&heights[stack.top()]>=heights[i]){
                stack.pop();
            }
            right[i]=stack.empty()?n:stack.top();
            stack.push(i);
        }
        while(!stack.empty()){
            stack.pop();
        }
        //left smaller nearest:
        for(int i=0;i<heights.size();i++){
            while(!stack.empty()&&heights[stack.top()]>=heights[i]){
                stack.pop();
            }
            left[i]=stack.empty()?-1:stack.top();
            stack.push(i);
        }
        //area:
        for(int i=0;i<heights.size();i++){
            area=(right[i]-left[i]-1)*heights[i];
            ans=max(ans,area);
        }  
        return ans;    
    }
};
