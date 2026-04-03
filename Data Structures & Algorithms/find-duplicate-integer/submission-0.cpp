class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high){
            int mid=(low+high)/2;
            int lessorequal=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid) lessorequal++;
            }
            if(lessorequal<=mid) low=mid+1;
            else high=mid;
        }
        return low;
    }
};
