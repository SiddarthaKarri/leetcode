class Solution {
public:
    string largestGoodInteger(string num) {
        int st=num[0]-'0',cnt=1,maxi=-1;
        for(int i=1;i<num.size();i++){
            if(num[i]-'0'==num[i-1]-'0'){
                cnt++;
                if(cnt==3)
                    maxi=max(maxi,num[i]-'0');
            } else
                cnt =1;
        }
        if (maxi==-1) return "";
        string res = std::to_string(maxi);
        return res+res+res;
    }
};