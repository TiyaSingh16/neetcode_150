class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>> res;
       vector<int> ans;
       dfs(0,n,res,ans,nums);
       return res;
    }
private:
    void dfs(int i,int n,vector<vector<int>>& res,vector<int>& ans,vector<int>& nums){
        if(i==n){
            res.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        dfs(i+1,n,res,ans,nums);
        ans.pop_back();
        dfs(i+1,n,res,ans,nums);
    }
};
