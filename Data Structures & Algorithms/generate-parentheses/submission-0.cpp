class Solution {
public:
    void backtrack(int openN,int closeN,int n,string& stack,vector<string>& res){
        if(openN==closeN && openN==n){
            res.push_back(stack);
            return;
        }
        if(openN<n){
            stack+='(';
            backtrack(openN+1,closeN,n,stack,res);
            stack.pop_back();
        }
        if(closeN<openN){
            stack+=')';
            backtrack(openN,closeN+1,n,stack,res);
            stack.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0,0,n,stack,res);
        return res;
    }
};
