
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long sum = maxHeights[i];
            int h = maxHeights[i];
            for (int j = i - 1; j >= 0; j--) {
                h = min(h, maxHeights[j]);
                sum += h;
            }
            h = maxHeights[i];
            for (int j = i + 1; j < n; j++) {
                h = min(h, maxHeights[j]);
                sum += h;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
