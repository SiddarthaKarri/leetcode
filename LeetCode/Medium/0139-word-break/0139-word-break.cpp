struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node* node = root;
        for(char c : word){
            if(!node->containsKey(c))
                node->put(c,new Node());

            node = node->get(c);
        }
        node->setEnd();
    }
};

class Solution {
public:
    // using dfs, rec -> it goes to 2^n , so tle will come
    // using dp memo it goes to n*len
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(auto &w:wordDict)
            trie.insert(w);
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i=0;i<n;i++){
            if(!dp[i]) 
                continue;
            Node* node = trie.root;
            for(int j=i;j<n;j++){
                if(!node->containsKey(s[j]))
                    break;
                node = node->get(s[j]);
                if(node->isEnd())
                    dp[j+1] = true;
            }
        }
        return dp[n];
    }
};