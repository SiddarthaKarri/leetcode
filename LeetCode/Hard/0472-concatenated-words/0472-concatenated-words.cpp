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
    bool dfs(string &word, int index, Node* root, int count,vector<int> &memo){
        if(index == word.size())
            return count >= 2;
        if(memo[index] != -1)
            return memo[index];
        Node* node = root;
        for(int i=index;i<word.size();i++){
            if(!node->containsKey(word[i]))
                break;
            node = node->get(word[i]);
            if(node->isEnd()){
                if(dfs(word, i+1, root, count+1,memo))
                    return memo[index]=true;
            }
        }
        return memo[index]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        for(auto &w : words)
            trie.insert(w);
        vector<string> res;
        for(auto &word:words){
            if(word.empty()) 
                continue;
            vector<int> memo(word.size(),-1);
            if(dfs(word,0,trie.root,0,memo))
                res.push_back(word);
        }
        return res;
    }
};