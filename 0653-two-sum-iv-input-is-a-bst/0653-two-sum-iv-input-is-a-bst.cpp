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
    void storeInorder(TreeNode* root,vector<int> &inorder){
        //base case
        if(root==NULL) return;
        //LNR
        
        //L
        storeInorder(root->left,inorder);
        //N
        inorder.push_back(root->val);
        //R
        storeInorder(root->right,inorder);
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        storeInorder(root,inorder);
        
        //find target sum using 2 ptr
        int s =0;
        int e = inorder.size()-1;
        while(s<e){
            int sum = inorder[s]+inorder[e];
            if(sum == k) return true;
            if(sum<k) s++;
            if(sum>k) e--;
            
        }
        
        return false;
    }
};