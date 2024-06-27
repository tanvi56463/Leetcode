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
    int height(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int finalAns = max(leftHeight,rightHeight)+1;
        return finalAns;
        
    }
    bool isBalanced(TreeNode* root){
        //BC
        if(root == NULL){
            return true;
        }
        
        //curr node->solve
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int finalAns = max(leftHeight,rightHeight);
        int diff = abs(leftHeight-rightHeight);
        
        
        bool currnodeAns = (diff<=1);
        
        bool LeftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);
        
        if(currnodeAns && LeftAns && rightAns){
            return true;
            
        }
        else{
            return false;
        }
    }
};