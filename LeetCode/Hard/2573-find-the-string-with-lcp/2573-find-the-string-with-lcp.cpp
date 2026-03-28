class Solution {
public:
    bool check(vector<vector<int>>&lcp, int n){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(lcp[i][j] > n-j) return false;
                if(lcp[i][j] != lcp[j][i]) return false;
                if(i == j && lcp[i][i] != n-i) return false;
            }
        }
        return true;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        bool f = check(lcp, n);
        if(f == 0)return "";
        char c = 'z';
        string as(n, '#'); as[n-1] = c;
        --c;
        for(int i=n-2;i>=0;i--){
            bool f = 0;
            for(int j=i+1;j<n;j++){
                if(lcp[i][j]>0){
                    as[i] = as[j];
                    f = 1; break;
                }
                else as[i] = c;
            }
            if(f == 0) --c;
        }
        if(c < (char)('a'-1)) return "";
//some checks on lcp to validate the string formed from lcp itself.
        for(int i=n-1;i>=0;i--){
            if(as[i]==as[n-1]){
                if(lcp[i][n-1]!=1)return "";
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=i;j--){
                if(as[i]==as[j]){
                    if(lcp[i][j] != lcp[i+1][j+1] + 1)return "";
                }else{
                    if(lcp[i][j]!=0)return "";
                }
            }
        }
//make lexo smaller
        char start = 'a';
        map<char,char> mp;
        for(int i=0;i<n;i++){
            if(mp.find(as[i]) == mp.end()){
                mp[as[i]] = start++;
            }
        }
        for(int i=0;i<n;i++){
            as[i] = mp[as[i]];
        }
        return as;
    }
};