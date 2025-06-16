class Solution {
public:
    int product(int n) {
        int pr = 1;
        while (n > 0) {
            pr *= (n % 10);
            n /= 10;
        }
        return pr;
    }
    int smallestNumber(int n, int t) {
        int temp = n;
        while (true) {
            if (product(temp) % t == 0)
                return temp;
            temp += 1;
        }
        return -1;
    }
};