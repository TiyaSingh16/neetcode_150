class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int res=r;;
        while(l<=r){
            int mid=(l+r)/2;
            if(can(weights,days,mid)){
                res=min(mid,res);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
private:
    bool can(vector<int>& weights, int days, int mid){
        int ship=1, curcap=mid;
        for(int w:weights){
            if(curcap-w<0){
                ship++;
                if(ship>days) return false;
                curcap=mid-w;
            }else{
                curcap-=w;
            }
        }
        return true;
    }
};