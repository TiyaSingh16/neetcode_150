#include <stack>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pair;
        stack<double> stack;
        double cur;
        for(int i=0;i<position.size();i++){
            pair.push_back({position[i],speed[i]});
        }
        sort(pair.rbegin(),pair.rend());
        stack.push(0);
        for(auto& p:pair){
            cur=stack.top();
            stack.push((double)(target-p.first)/p.second);
            if(cur>=stack.top()){
                stack.pop();
            }
        }
        return stack.size()-1;
    }
};
