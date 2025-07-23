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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int,map<int,multiset<int>>> nodes;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* nd = p.first;
            int x=p.second.first, y=p.second.second;
            nodes[x][y].insert(nd->val);
            if(nd->left)
                q.push({nd->left,{x-1,y+1}});
            if(nd->right)
                q.push({nd->right,{x+1,y+1}});
        }
        for(auto p:nodes){
            vector<int> col;
            for(auto a:p.second)
                col.insert(col.end(),a.second.begin(),a.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};