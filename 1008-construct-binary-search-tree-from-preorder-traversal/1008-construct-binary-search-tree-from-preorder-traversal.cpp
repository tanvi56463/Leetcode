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
    TreeNode* build(int&i,int min,int max, vector<int>& preoder){
        if(i>= preoder.size()){ return nullptr;}
        TreeNode* root = nullptr;
        if(preoder[i]>min && preoder[i]<max){
            root = new TreeNode(preoder[i++]);
            root->left = build(i, min,root->val,preoder);
            root->right = build(i, root->val,max,preoder);
        }
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min = INT_MIN;
        int max = INT_MAX;
        int i = 0;
        return build(i,min,max,preorder);
    }
};