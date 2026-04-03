class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int col=matrix[0].size();
        int top=0, bot=rows-1;
        while(top<=bot){
            int mid=(bot+top)/2;
            if(target<matrix[mid][0]){
                bot--;
            }
            else if(target>matrix[mid][col-1]){
                top++;
            }
            else{
                break;
            }
        }
        if(!(top<=bot)){
            return false;
        }
        int mid=(top+bot)/2;
        int l=0,r=col-1;
        while(l<=r){
            int m=(l+r)/2;
            if(target<matrix[mid][m]){
                r--;
            }
            else if(target>matrix[mid][m]){
                l++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
