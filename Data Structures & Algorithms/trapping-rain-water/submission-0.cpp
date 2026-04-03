class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int l=0,r=height.size()-1;
        int maxl=height[l],maxr=height[r];
        int trapw=0;
        while(l<r){
            if(maxl<maxr){
                l++;
                maxl=max(height[l],maxl);
                trapw+=maxl-height[l];
            }
            else{
                r--;
                maxr=max(height[r],maxr);
                trapw+=maxr-height[r];
            }
        }
        return trapw;
    }
};
