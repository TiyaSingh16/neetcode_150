class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int target = -nums[i];
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicates for j
                    while (j < k && nums[j] == nums[j+1]) j++;
                    // Skip duplicates for k
                    while (j < k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                }
            }
        }
        return res;
    }
};
