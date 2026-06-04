class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        dfs(nums,target,res,0,0,ans);
        return res;
    }
private:
    void dfs(vector<int>& nums, int target,vector<vector<int>>& res, int i,int total,vector<int>& ans){
        if(total==target){
            res.push_back(ans);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(total+nums[j]>target){
                return;
            }
            ans.push_back(nums[j]);
            dfs(nums,target,res,j,total+nums[j],ans);
            ans.pop_back();
        }
    }
};
