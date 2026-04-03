class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto &p:strs){
            res+=to_string(p.size())+"#"+p;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            i=j+1;
            res.push_back(s.substr(i,length));
            j=i+length;
            i=j;
        }
        return res;
    }
};
