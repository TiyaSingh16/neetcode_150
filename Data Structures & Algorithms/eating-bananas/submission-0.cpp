class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        int ans=r;//max time taken by kuku
        while(l<=r){
            int k=(l+r)/2;
            int time=0;
            for(int p:piles){
                time+=ceil(static_cast<double>(p)/k);
            }
            if(time<=h){
                r=k-1;
                ans=k;
            }
            else{
                l=k+1;
            }
        }
        return ans;
    }
};
