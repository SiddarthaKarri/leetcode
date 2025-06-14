class Solution {
public:
    bool isBalanced(string num) {
        int sume = 0, sumo = 0;
        for (int i = 0; i < num.size(); i++) {
            int digit = num[i] - '0';
            if (i % 2 == 0)
                sume += digit;
            else
                sumo += digit;
        }
        if (sume != sumo)
            return false;
        return true;
    }
};