class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int i=0,j=0,val=0;
        vector<int> res(temperatures.size(),0);
        for(i=0;i<temperatures.size();i++){
            for(j=i+1;j<temperatures.size();j++){
                if(temperatures[i]<temperatures[j]){
                    val=j-i;
                    break;
                }
            }
            res[i]=val;
            val=0;
        }
        return res;
    }
};
