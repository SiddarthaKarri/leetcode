#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& nums) {
        auto lcm = [](long long a,long long b) {
            return (a / (std::gcd(a, b))*b);
        };
        long long ogcd = nums[0], olcm = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ogcd = std::gcd(ogcd,nums[i]);
            olcm = lcm(olcm,nums[i]);
        }
        long long maxfs = ogcd * olcm;
        for (int i = 0; i < nums.size(); i++) {
            long long cgcd = 0, clcm = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    cgcd = std::gcd(cgcd, nums[j]);
                    clcm = lcm(clcm, nums[j]);
                }
            }
            long long fs = cgcd * clcm;
            maxfs = std::max(maxfs, fs);
        }
        return maxfs;
    }
};