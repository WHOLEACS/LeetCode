class Solution {
public:
    // 队列queue
    bool canReach(string s, int minJump, int maxJump) {
        int len = s.size();
        if (s[len-1] == '1') {
            return false;
        }
        vector<int> vec;
        vec.clear();
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                vec.emplace_back(i);
            }
        }
        int m = vec.size();
        vector<bool> can_reach(len, false);
        can_reach[0] = true;
        deque<int> dq;
        while (!dq.empty()) {
            dq.pop_back();
        }
        int ptr = 0;
        for (int i = 1; i < m; i++) {
            while (ptr < m && vec[ptr] + minJump <= vec[i]) {
                if (can_reach[vec[ptr]]) {
                    dq.emplace_back(vec[ptr]);
                }
                ptr++;
            }
            while (!dq.empty() && dq.front() < vec[i] - maxJump) {
                dq.pop_front();
            }
            can_reach[vec[i]] = !dq.empty();
        }
        return can_reach[vec[m-1]];
    }
};
