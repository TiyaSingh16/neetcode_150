/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        dfs(root,res);
        return res;
    }
private:
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        int leftm=dfs(root->left,res);
        int rightm=dfs(root->right,res);
        leftm=max(0,leftm);
        rightm=max(0,rightm);
        res=max(res,root->val+leftm+rightm);
        return root->val+max(leftm,rightm);
    }
};
