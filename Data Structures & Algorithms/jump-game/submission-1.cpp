class Solution {
public:
    bool canJump(vector<int>& nums) {
        int tar=nums.size()-1;
        int i=tar-1;
        while(tar!=0 && i>=0){
            if(i+nums[i]>=tar){
                tar=i;
            }
            i--;
        }
        return tar==0;
    }
};
