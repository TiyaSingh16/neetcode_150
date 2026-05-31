/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> st,ed;
        for(auto interval:intervals){
            st.push_back(interval.start);
            ed.push_back(interval.end);
        }
        sort(st.begin(),st.end());
        sort(ed.begin(),ed.end());
        int s=0,e=0,count=0,res=0;
        while(s<intervals.size()){
            if(st[s]<ed[e]){
                count++;
                s++;
            }else{
                count--;
                e++;
            }
            res=max(res,count);
        }
        return res;
    }
};
