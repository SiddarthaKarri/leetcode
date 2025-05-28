class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string temp = s;
        char i = '\0';
        for(auto &c:temp){
            if(i=='\0' && c!='9') i = c;
            if(c==i) c = '9';
        }
        string temp2 = s;
        i = '\0';
        for(auto &c:temp2){
            if(i=='\0' && c!='0') i = c;
            if(c==i) c = '0';
        }
        return stoi(temp) - stoi(temp2);
    }
};
