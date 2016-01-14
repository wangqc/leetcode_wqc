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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if(size == 0){
            return NULL;
        }
        return backTrack(preorder, inorder, 0, size-1, 0, size-1);
    }
    
    TreeNode* backTrack(vector<int>& preorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd){
        if(pStart > pEnd){
            return NULL;
        }
        int i;
        for(i = iStart; i < iEnd; i++){
            if(inorder[i] == preorder[pStart]){
                break;
            }
        }
        int leftLen = i - iStart;
        int rightLen = iEnd - i;
        TreeNode* root = new TreeNode(preorder[pStart]);
        root->left = backTrack(preorder, inorder, pStart + 1, pStart + leftLen, iStart, i -1);
        root->right = backTrack(preorder, inorder, pEnd - rightLen + 1, pEnd, i + 1, iEnd);
        return root;
    }
};
