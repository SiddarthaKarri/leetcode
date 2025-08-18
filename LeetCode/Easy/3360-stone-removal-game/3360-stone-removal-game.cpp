class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10)
            return false;
        int alice = 10, bob = 0;
        while (n > 0) {
            if (n < alice) {
                if (bob == 0)
                    return false;
                return true;
            } else
                n -= alice;
            alice--;
            bob ^= 1;
        }
        if (bob == 0)
            return false;
        return true;
    }
};