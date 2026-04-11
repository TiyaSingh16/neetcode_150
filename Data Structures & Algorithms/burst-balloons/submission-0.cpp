class Solution {
public:
    int f(int i,int j, vector<vector<int>> &dp, vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int idx=i;idx<=j;idx++){
            int cost=nums[i-1]*nums[idx]*nums[i+1]+f(i,idx-1,dp,nums)+f(idx+1,j,dp,nums);
            maxi=max(cost,maxi);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n+2,vector<int> (n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                int maxi=0;
                for (int k = i; k <= j; k++) {
                    int cost = a[i - 1] * a[k] * a[j + 1]
                             + dp[i][k - 1]
                             + dp[k + 1][j];

                    maxi = max(maxi, cost);
                }

                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};
