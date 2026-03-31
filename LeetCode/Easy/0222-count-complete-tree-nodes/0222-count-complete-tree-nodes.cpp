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
    // void inorder(TreeNode* root, int &cnt) {
    //     if(!root)
    //         return;
    //     cnt++;
    //     inorder(root->left, cnt);
    //     inorder(root->right, cnt);
    // }
    // int countNodes(TreeNode* root) {
    //     if(!root)
    //         return 0;
    //     int cnt=0;
    //     inorder(root,cnt);
    //     return cnt;
    // }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if(lh==rh)
            return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int findHeightLeft(TreeNode* node) {
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }

    int findHeightRight(TreeNode* node) {
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
};