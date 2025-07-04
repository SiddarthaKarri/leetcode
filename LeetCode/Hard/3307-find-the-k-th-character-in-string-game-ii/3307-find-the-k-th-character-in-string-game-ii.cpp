class Solution {
public:
    char shift(char c, int x=1) {
        return 'a'+((c-'a'+x)%26);
    }
    char kthCharacter(long long k, vector<int>& operations) {
        int sh=0;
        vector<long long> lengths;
        long long len=1;
        for(int op:operations){
            len*=2;
            lengths.push_back(len);
            if(len>=k) break;
        }
        for(int i=lengths.size()-1;i>=0;--i){
            long long half=lengths[i]/2;
            if(k>half){
                k-=half;
                if(operations[i]==1) sh++;
            }
        }
        return shift('a',sh);
    }
};