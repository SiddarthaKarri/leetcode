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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<vector<int>> lvl = lvlOrder(root);
        for(auto i:lvl)
            ans.push_back(i.back());
        return ans;
    }
private:
    vector<vector<int>> lvlOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> lvl;
            for(int i=0;i<size;i++){
                TreeNode* n = q.front();
                q.pop();
                lvl.push_back(n->val);
                if(n->left!=NULL)
                    q.push(n->left);
                if(n->right!=NULL)
                    q.push(n->right);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};