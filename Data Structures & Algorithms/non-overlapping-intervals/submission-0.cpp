class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end());
        int preve=intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {

            if(preve <= intervals[i][0]) {
                preve = intervals[i][1];
            }
            else {
                count++;
                preve = min(preve, intervals[i][1]);
            }
        }
        return count;
    }
};
