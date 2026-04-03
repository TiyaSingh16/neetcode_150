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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;

        while (curr) {
            // Case 1: No left child
            if (!curr->left) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            // Case 2: Has left child
            else {
                TreeNode* prev = curr->left;

                // Find inorder predecessor
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                // Make temporary thread
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                }
                // Thread exists → remove it
                else {
                    prev->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
    int kthSmallest(TreeNode* root, int k) {
       vector<int> ans=inorderTraversal(root);
       return ans[k-1];
        }
};