class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1;
        int ans=nums[0];
        while(l<=r){
            if(nums[l]<nums[r]){
                ans=min(ans,nums[l]);
                break;
            }
            else{
                int m=(l+r)/2;
                
                if(nums[m]>=nums[l]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
                ans=min(ans,nums[m]);
            }
        }
        return ans;
    }
};
