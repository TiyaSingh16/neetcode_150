class Solution {
public:
    int sumofsquares(int n){
        int res=0;
        while(n){
            res+=pow((n%10),2);
            n/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        set<int> hashset;
        while(hashset.find(n)==hashset.end()){
            hashset.insert(n);
            n=sumofsquares(n);
            if(n==1) return true;
        }
        return false;
    }
};
