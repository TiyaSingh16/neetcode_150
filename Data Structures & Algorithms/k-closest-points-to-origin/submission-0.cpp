class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxheap;
        for(auto point: points){
                int val=pow(point[0],2)+pow(point[1],2);
                maxheap.push({val,point});
            }
        while(maxheap.size()>k){
            maxheap.pop();
        }
        vector<vector<int>> res;
        while(!maxheap.empty()){
            res.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return res;
    }
};
