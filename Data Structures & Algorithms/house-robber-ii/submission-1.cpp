class Solution {
public:
    vector<int> dp1;
    vector<int> dp2;     
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return nums[0];
        dp1.resize(n,-1);
        dp2.resize(n,-1);
        return max(dfs(nums,0,n-2,dp1),dfs(nums,1,n-1,dp2));
    }
    int dfs(vector<int>& nums, int i, int j,vector<int>& dp){
        if(i>j) return 0;
        if(dp[i]!=-1) return dp[i];
        dp[i]=max(dfs(nums,i+1,j,dp),nums[i]+dfs(nums,i+2,j,dp));
        return dp[i];
    }
};
