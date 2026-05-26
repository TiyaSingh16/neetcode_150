class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        if(n>=0){
            for(int i=1;i<=n;i++){
                res*=x;
            }
            return res;
        }else{
            n=-n;
            for(int i=1;i<=n;i++){
                res*=x;
            }
            return (((double)1)/res);
        }
    }
};
