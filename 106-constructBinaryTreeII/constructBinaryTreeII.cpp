class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int sizeIn = inorder.size();
        int sizePost = postorder.size();
        if(!sizeIn || sizeIn != sizePost){
            return NULL;
        }
        return buildTreeBT(inorder, postorder, 0, sizeIn-1, 0, sizePost-1);
    }
    
    TreeNode* buildTreeBT(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int pStart, int pEnd){
        TreeNode* root = new TreeNode(postorder[pEnd]);
        if(pStart == pEnd){
            return root;
        }
        else{
            int i;
            for(i = inStart; i <= inEnd; i++){
                if(inorder[i] == postorder[pEnd]){
                    break;    
                }
            }
            int leftPart = i - inStart;
            int rightPart = inEnd - i;
            if(leftPart){
                root->left = buildTreeBT(inorder, postorder, inStart, i-1, pStart, pStart+leftPart-1);
            }
            if(rightPart){
                root->right = buildTreeBT(inorder, postorder, i+1, inEnd, pEnd - rightPart, pEnd-1);
            }
            return root;
        }
    }
};
