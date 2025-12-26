class Solution {
public:
    int bestClosingTime(string customers) {
        int bst=0,mini=0,pre=0;
        for(int i=0;i<customers.length();i++){
            pre += customers[i] == 'Y' ? -1:1;
            if(pre<mini){
                bst = i+1;
                mini = pre;
            }
        }
        return bst;
    }
};