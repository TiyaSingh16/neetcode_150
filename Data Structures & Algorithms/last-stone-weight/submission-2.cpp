class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(auto num: stones){
            maxheap.push(num);
        }
        while (maxheap.size() > 1){
            int x=maxheap.top();
            maxheap.pop();
            int y=maxheap.top();
            maxheap.pop();
            int z=x-y;
            if(abs(z)>0){
                maxheap.push(abs(z));
            }
        }
        return (maxheap.empty())?0:maxheap.top();
    }
};
