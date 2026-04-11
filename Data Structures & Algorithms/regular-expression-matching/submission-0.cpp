class Solution {
public:
    bool dfs(int i,int j,string& s, string& p,int m,int n,vector<vector<int>>& dp){
        if(j==n && i==m) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool match=i<m && (s[i]==p[j]||p[j]=='.');
        if(j+1<n && p[j+1]=='*'){
            dp[i][j]=dfs(i,j+2,s,p,m,n,dp)||(match && dfs(i+1,j,s,p,m,n,dp));
        }else{
            dp[i][j]=match && dfs(i+1,j+1,s,p,m,n,dp);
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return dfs(0,0,s,p,m,n,dp);
    }
};
