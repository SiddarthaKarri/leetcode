class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int inDegree[n];
        memset(inDegree, 0, sizeof(inDegree));
        for (auto& edge : edges)
            ++inDegree[edge[1]];
        int champion = -1;
        int zeroInDegreeCount = 0;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) { 
                ++zeroInDegreeCount;
                champion = i;
            }
        }
        return zeroInDegreeCount == 1 ? champion : -1;
    }
};