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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        bool chk=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> rs(size);
            for(int i=0;i<size;i++){
                TreeNode* nd = q.front();
                q.pop();
                int ind = chk ? i : size-i-1;
                rs[ind] = nd->val;
                if(nd->left)
                    q.push(nd->left);
                if(nd->right)
                    q.push(nd->right);
            }
            chk = !chk;
            res.push_back(rs);
        }
        return res;
    }
};