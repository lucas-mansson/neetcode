class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxProf = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int currProf = prices[r] - prices[l];
                maxProf = max(currProf, maxProf);
            } else {
                l = r;
            }
            r++;
        }
        return maxProf;
    }
};
