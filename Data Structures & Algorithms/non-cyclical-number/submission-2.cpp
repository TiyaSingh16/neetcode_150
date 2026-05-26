class Solution {
public:
    int sumofsquares(int n){
        int res=0;
        while(n){
            res+=(n%10)*(n%10);
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow=n,fast=sumofsquares(n);
        while(slow!=fast){
            slow=sumofsquares(slow);
            fast=sumofsquares(fast);
            fast=sumofsquares(fast);
        }
        return fast==1;
    }
};
