class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[r][c] != -1) return dp[r][c];

        int m = matrix.size();
        int n = matrix[0].size();

        int res = 1;

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        for(auto [dr, dc] : dir){
            int nr = r + dr;
            int nc = c + dc;

            if(nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc] > matrix[r][c]){
                res = max(res, 1 + dfs(nr, nc, matrix, dp));
            }
        }

        return dp[r][c] = res;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int final = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                final = max(final, dfs(i, j, matrix, dp));
            }
        }

        return final;
    }
};