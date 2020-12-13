class Solution {
public:
    //双队列
    string predictPartyVictory(string senate) {
        int len = senate.size();
        if (len <= 1) {
          return len == 1 && senate[0] == 'R' ? "Radiant" : "Dire";  
        }
        queue<int> R;
        queue<int> D;
        while (!R.empty()) R.pop();
        while (!D.empty()) D.pop();
        for (int i = 0; i < len; i++) {
            if (senate[i] == 'R') {
                R.push(i);
            } else {
                D.push(i);
            }
        }
        while (!R.empty() && !D.empty()) {
            int rad = R.front();
            int dire = D.front();
            R.pop(), D.pop();
            if (rad < dire) {
                R.push(rad + len);
            } else {
                D.push(dire + len);
            }
        }
        if (R.empty()) return "Dire";
        return "Radiant";
    }
};
