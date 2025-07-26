class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& p) {

        const int m = static_cast<int>(p.size());
        /* ---------------- 1. build adjacency buckets ---------------- */
        vector<vector<pair<int,int>>> atLeft(n + 2);   // edges grouped by left endpoint
        for (int i = 0; i < m; ++i) {
            int a = p[i][0], b = p[i][1];
            if (a > b) swap(a, b);                     // store as (min, max)
            atLeft[a].push_back({b, i});               // {rightEnd, pairID}
        }

        /* ---------------- 2. sweep from right to left ----------------
           multiset keeps all edges whose left endpoint ≤ current l    */
        multiset<pair<int,int>> ms;                    // {rightEnd, pairID}
        vector<int> first_b(n + 2), second_b(n + 2), first_id(n + 2);

        for (int l = n; l >= 1; --l) {
            for (auto &e : atLeft[l]) ms.insert(e);    // activate new edges

            if (!ms.empty()) {
                auto it  = ms.begin();                 // smallest rightEnd
                first_b[l]  = it->first;
                first_id[l] = it->second;

                auto it2 = std::next(it);
                second_b[l] = (it2 != ms.end() ? it2->first : n + 1);
            } else {
                first_b[l]  = n + 1;                   // no conflict at all
                second_b[l] = n + 1;
                first_id[l] = -1;
            }
        }

        /* ---------------- 3. prefix sums for baseline + per pair ---- */
        long long baseline = 0;                        // total when nothing removed
        vector<long long> sum1k(m), sum2k(m);          // contribution tables

        for (int l = 1; l <= n; ++l) {
            long long d1 = 1LL * first_b[l]  - l;      // subarrays allowed by 1st stop
            long long d2 = 1LL * second_b[l] - l;      // what we’d get if that stop vanished
            baseline += d1;

            int id = first_id[l];
            if (id >= 0) {                             // edge i is the 1st stopper here
                sum1k[id] += d1;
                sum2k[id] += d2;
            }
        }

        /* ---------------- 4. try deleting each pair ----------------- */
        long long best = 0;
        for (int i = 0; i < m; ++i) {
            long long cand = baseline - sum1k[i] + sum2k[i];
            best = max(best, cand);
        }
        return best;
    }
};