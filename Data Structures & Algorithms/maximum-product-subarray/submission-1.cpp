class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curmax=1,curmin=1;
        for(int n:nums){
            int temp=curmax;
            curmax=max(max(curmax*n,curmin*n),n);
            curmin=min(min(temp*n,curmin*n),n);
            res=max(res,curmax);
        }
        return res;
    }
};
