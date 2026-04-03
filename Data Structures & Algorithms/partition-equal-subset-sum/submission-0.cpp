class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return false;
        int target=sum/2;
        unordered_set<int> dp;
        dp.insert(0);
        for(int i=0;i<nums.size();i++){
            unordered_set<int> nxtdp=dp;
            for(auto t:dp){
                if(t==target) return true;
                nxtdp.insert(t+nums[i]);
            }
            dp=nxtdp;
        }
        return dp.find(target) != dp.end();
    }
};
