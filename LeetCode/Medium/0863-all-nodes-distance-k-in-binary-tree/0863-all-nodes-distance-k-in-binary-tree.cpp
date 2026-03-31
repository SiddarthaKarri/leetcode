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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) 
            return {};
        unordered_map<TreeNode*, TreeNode*> par;
        mpp(root, par);
        return bfs(target, par, k);
    }
    void mpp(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& par) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* nd=q.front();
            q.pop();
            if(nd->left){
                par[nd->left]=nd;
                q.push(nd->left);
            }
            if(nd->right){
                par[nd->right]=nd;
                q.push(nd->right);
            }
        }
    }
    vector<int> bfs(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& par, int k) {
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int cur=0;
        while(!q.empty()){
            int size=q.size();
            if(cur++==k)
                break;
            for(int i=0;i<size;i++){
                TreeNode* nd=q.front();
                q.pop();
                if(nd->left && vis.find(nd->left) == vis.end()){
                    vis.insert(nd->left);
                    q.push(nd->left);
                }
                if(nd->right && vis.find(nd->right) == vis.end()){
                    vis.insert(nd->right);
                    q.push(nd->right);
                }
                if(par.count(nd) && vis.find(par[nd]) == vis.end()){
                    vis.insert(par[nd]);
                    q.push(par[nd]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};