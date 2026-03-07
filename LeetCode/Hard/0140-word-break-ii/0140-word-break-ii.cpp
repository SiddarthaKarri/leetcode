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

    vector<string> dfs(int index, string &s, Node* root,unordered_map<int, vector<string>>& memo) {
        if(memo.count(index))
            return memo[index];
        if(index == s.size())
            return {""};
        vector<string> result;
        Node* node = root;
        for(int i=index;i<s.size();i++){
            if(!node->containsKey(s[i]))
                break;
            node = node->get(s[i]);
            if(node->isEnd()){
                string word = s.substr(index, i-index+1);
                vector<string> rest = dfs(i+1,s,root,memo);
                for(string &sentence:rest){
                    if(sentence == "")
                        result.push_back(word);
                    else
                        result.push_back(word + " " + sentence);
                }
            }
        }
        memo[index] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(auto &w : wordDict)
            trie.insert(w);
        unordered_map<int, vector<string>> memo;
        return dfs(0, s, trie.root,memo);
    }
};