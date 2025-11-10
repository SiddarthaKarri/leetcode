class Solution {
public:
    int f(int start,int end,vector<int>& ages,int curr){
        int ind=curr;
        while(start<=end){
            int mid=(start+end)/2;
            if((0.5*ages[curr]+7)>=ages[mid] || ages[mid]>ages[curr] || (ages[mid]>100 && ages[curr]<100))
                start=mid+1;
            else{
                ind=mid;
                end=mid-1;
            }
        }
        return ind;
    }
    int uf(int start,int end,vector<int>& ages,int curr){
        int ind=curr;
        while(start<=end){
            int mid=(start+end)/2;
            if((0.5*ages[curr]+7)>=ages[mid] || ages[mid]>ages[curr] || (ages[mid]>100 && ages[curr]<100))
                end=mid-1;
            else{
                ind=mid;
                start=mid+1;
            }
        }
        return ind;
    }
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int cnt=0;
        int n=ages.size();
        for(int i=0;i<n;i++){
            int curr=i;
            int lower=f(0,i,ages,curr);
            int upper=uf(i,n-1,ages,curr);
            cnt+=(curr-lower)+(upper-curr);
        }
        return cnt;
    }
};