class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int sol=INT_MIN;
        for(int i=0;i<colors.size()-1;i++)
            for(int j=i+1;j<colors.size();j++)
                if(colors[i]!=colors[j])
                    sol = max(sol,abs(i-j));
        return sol;
    }
};