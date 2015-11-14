/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root){
            return res;
        }
        string path;
        path = path + to_string(root->val);
        searchPath(res, path, root);
        return res;
    }
    
    void searchPath(vector<string> & res, string path, TreeNode* root){
        if(root->left){
            searchPath(res, path + "->" + to_string(root->left->val), root->left);
        }
        if(root->right){
            searchPath(res, path + "->" + to_string(root->right->val), root->right);
        }
        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }
    }
};
