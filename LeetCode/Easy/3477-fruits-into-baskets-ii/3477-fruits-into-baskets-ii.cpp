class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int p = fruits.size(), q = baskets.size();
        vector<int> chq(q, 0);
        int mt = 0;
        for (int a = 0; a < p; a++) {
            int temp = 0;
            for (int b = 0; b < q; b++) {
                if (!chq[b] && baskets[b] >= fruits[a]) {
                    chq[b] = 1;
                    temp = 1;
                    break;
                }
            }
            if (!temp)
                mt++;
        }
        return mt;
    }
};