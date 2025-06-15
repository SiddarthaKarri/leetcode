class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int BITS = 32;
        int maxi = 0;
        for (int i = 0; i < BITS; i++) {
            int bitC = 0;
            for (int num : candidates) {
                if ((num >> i) & 1)
                    bitC++;
            }
            maxi = std::max(maxi, bitC);
        }
        return maxi;
    }
};