class Solution {
public:
    int f(int idx,int sum,vector<int>& nums,vector<vector<int>>& dp){
        if(idx == 0){
        if(sum == 0 && nums[0] == 0) return 2;
        if(sum == 0 || nums[0] == sum) return 1;
        return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int nottake=f(idx-1,sum,nums,dp);
        int take=0;
        if(nums[idx]<=sum) take=f(idx-1,sum-nums[idx],nums,dp);
        return dp[idx][sum]=nottake+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        if((target+total)%2!=0) return 0;
        if(target > total || target < -total) return 0;
        int sum1=(target+total)/2;
        vector<vector<int>> dp(n,vector<int>(sum1+1,-1));
        return f(n-1,sum1,nums,dp);
    }
};
