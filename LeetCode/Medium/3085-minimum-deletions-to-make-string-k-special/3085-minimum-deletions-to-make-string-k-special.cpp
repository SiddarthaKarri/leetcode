class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> fq(26,0);
        for(auto& i:word)
            fq[i-'a']++;
        sort(begin(fq),end(fq));
        int l=0;
        while(fq[l]==0)
            l++;
        int res=INT_MAX;
        for(int i=l;i<fq.size();i++){
            int tot=fq[i];
            for(int j=i+1;j<fq.size();j++)
                if(fq[j]>fq[i]+k)
                    tot += fq[i]+k;
                else
                    tot+=fq[j];
            int rem=word.size()-tot;
            res = min(res,rem);
        }
        return res;
    }
};