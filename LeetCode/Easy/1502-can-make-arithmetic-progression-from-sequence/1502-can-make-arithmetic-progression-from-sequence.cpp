class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) 
            return true;
        int mini = *min_element(arr.begin(),arr.end()),maxi = *max_element(arr.begin(),arr.end());
        // intutive thought --> a+(n-1)*d
        if((maxi-mini)%(n-1)!=0) 
            return false;
        int d = (maxi-mini)/(n-1);
        unordered_set<int> s(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int gues = mini+i*d;
            if(s.find(gues)==s.end())
                return false;
        }
        return true;
    }
    // Sorting
        // sort(arr.begin(),arr.end());
        // int diff = abs(arr[1]-arr[0]);
        // for(int i=1;i<arr.size();i++){
        //     if(arr[i]-arr[i-1]==diff)
        //         continue;
        //     else
        //         return false;
        // }
        // return true;
};