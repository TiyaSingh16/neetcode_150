class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totg=0,totc=0;
        int start=0,curg=0;
        for(int i=0;i<gas.size();i++){
            totg+=gas[i];
            totc+=cost[i];
            curg+=gas[i]-cost[i];
            if(curg<0){
                start=i+1;
                curg=0;
            }
        }
        return (totg<totc)?-1:start;
    }
};
