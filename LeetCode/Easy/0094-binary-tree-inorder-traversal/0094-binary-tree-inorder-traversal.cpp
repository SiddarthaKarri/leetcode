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
        // vector<int> in;
        // stack<TreeNode*> st;
        // TreeNode* nd=root;
        // while(true){
        //     if(nd!=NULL){
        //         st.push(nd);
        //         nd = nd->left;
        //     } else {
        //         if(st.empty())
        //             break;
        //         nd=st.top();
        //         st.pop();
        //         in.push_back(nd->val);
        //         nd = nd->right;
        //     }
        // }
        // return in;

        // morris inorder
        vector<int> inorder;
        TreeNode* cur = root;
        while(cur!=NULL){
            if (cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};