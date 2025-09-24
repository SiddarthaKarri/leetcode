class Solution {
public:
    string simplifyDecimalPart(string s) {
     while (!s.empty() && s.back() == '0')
            s.pop_back();
        if (s.empty()) return "0";
        int n = s.size();
        for (int len = 1; len <= n / 2; ++len) {
            string pattern = s.substr(0, len);
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (s[i] != pattern[i % len]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return "(" + pattern + ")";
        }
        return s;
    }
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return res;
        res += ".";
        string frac;
        int count = 0;
        while (rem != 0 && count < 200) {
            rem *= 10;
            frac += '0' + (rem / d);
            rem %= d;
            count++;
        }
        res += simplifyDecimalPart(frac);
        return res;
    }
};