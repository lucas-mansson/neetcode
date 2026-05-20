class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freqs{}; // number, frequency
        for (int const& n : nums) {
            auto it = freqs.find(n);
            if(it != freqs.end()) {
                it->second++;
            } else {
                freqs.insert({n, 1});
            }
        }

        priority_queue<pair<int, int>> pq{};
        for(auto const& [k, v] : freqs) {
            pq.push({v, k}); // frequency, number
        }


        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
