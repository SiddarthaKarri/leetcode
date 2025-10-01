class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        while(numBottles>=numExchange){
            cnt += numBottles/numExchange;
            int c = numBottles%numExchange;
            numBottles /= numExchange;
            numBottles += c;
        }
        return cnt;
    }
};