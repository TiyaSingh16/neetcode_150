class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]=i;
        }
        vector<int> res;
        int size=0,end=0;
        for(int i=0;i<s.size();i++){
            size+=1;
            end=max(end,hash[s[i]]);
            if(end==i){
                res.push_back(size);
                size=0;
            }
        }
        return res;
    }
};
