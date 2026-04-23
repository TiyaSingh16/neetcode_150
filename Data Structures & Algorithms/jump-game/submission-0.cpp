class Solution {
public:
    bool canJump(vector<int>& nums) {
        int tar=nums.size()-1;
        int i=tar-1;
        for(int i=tar-1;i>=0;i--){
            if(i+nums[i]>=tar){
                tar=i;
            }
        }
        return tar==0;
    }
};
