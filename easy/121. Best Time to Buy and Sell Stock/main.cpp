class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int min_before = prices[0], max_ans = 0;
        for (int i=1; i < prices.size() ; i++){
            max_ans = max(max_ans, prices[i]-min_before);
            min_before = min(min_before, prices[i]);
        }
        return max_ans;
    }
};
