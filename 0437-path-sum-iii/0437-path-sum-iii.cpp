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
    int ans =0;
    void pathFromOneRoot(TreeNode* root, long long sum){
        if(!root) return;
        if(sum == root->val){
            ans++;
            
        }
        pathFromOneRoot(root->left, sum-root->val);
        pathFromOneRoot(root->right, sum-root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(root){
           pathFromOneRoot(root,targetSum); // fun call for main root
           pathSum(root->left,targetSum); // fun call for main root ka left node
           pathSum(root->right,targetSum); // fun call for main root ka right node
        }
        return ans;
    }
};