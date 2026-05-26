class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n=digits.size();
        int carry=0;
        if(digits[n-1]==9){
            res.insert(res.begin(),0);
            carry=1;
        }else{
            res.insert(res.begin(),digits[n-1]+1);
            carry=0;
        }
        for(int i=n-2;i>=0;i--){
            if(carry==1){
                if(digits[i]==9){
                    res.insert(res.begin(),0);
                    carry=1;
                }else{
                    res.insert(res.begin(),digits[i]+1);
                    carry=0;
                }
            }else{
                res.insert(res.begin(),digits[i]);
            }
        }
        if(carry==1) res.insert(res.begin(),1);
        return res;
    }
};
