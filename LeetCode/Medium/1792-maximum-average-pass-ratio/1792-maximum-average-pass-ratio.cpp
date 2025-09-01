class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };
        priority_queue<pair<double, pair<int, int>>> pq;
        for (const auto& c : classes) {
            double g = gain(c[0], c[1]);
            pq.push({g, {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto [g, classInfo] = pq.top();
            pq.pop();
            int pass = classInfo.first, total = classInfo.second;
            pq.push({gain(pass + 1, total + 1), {pass + 1, total + 1}});
        }
        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto [g, classInfo] = pq.top();
            pq.pop();
            int pass = classInfo.first, total = classInfo.second;
            totalRatio += (double)pass / total;
        }
        return totalRatio / classes.size();
    }
};