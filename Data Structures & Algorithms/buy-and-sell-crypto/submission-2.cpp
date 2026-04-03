class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1;
        int maxp=0; //max profit
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int profit=prices[r]-prices[l]; //profit on that day
                maxp=max(maxp,profit);
            }
            else{
                l=r;
            }
            r++;
        }
        return maxp;
    }
};
