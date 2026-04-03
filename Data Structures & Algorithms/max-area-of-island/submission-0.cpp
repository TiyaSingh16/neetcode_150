class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    
    int maxAreaOfIsland(vector<vector<int>>& grid) { 
        int area=0, ROWS=grid.size(),COLS=grid[0].size();
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]==1){
                    area=max(area,dfs(grid,i,j));
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>>& grid, int r,int c){
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c]=0;
        int res=1;
        for(int i=0;i<4;i++){
            res+=dfs(grid,r+directions[i][0],c+directions[i][1]);
        }
        return res;
    }
};
