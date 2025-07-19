class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_set<string> top;
        for(const string& path:folder){
            bool chk = false;
            for(size_t i=1;i<path.size()&&!chk;i++)
                if(path[i]=='/')
                    if(top.count(path.substr(0,i)))
                        chk = true;
            if(!chk) 
                top.insert(path);
        }
        return {top.begin(),top.end()};
    }
};