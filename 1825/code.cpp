class MKAverage {
private:
    multiset<int> lower;
    multiset<int> middle;
    multiset<int> upper;
    queue<int> pq;
    int m, k, sum = 0;
public:
    MKAverage() {
        lower.clear();
        middle.clear();
        upper.clear();
        while (!pq.empty()) {
            pq.pop();
        }
    }

    // 维护三个multiset
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    
    void addElement(int num) {
        if (!lower.empty() && num <= *(lower.rbegin())) {
            lower.insert(num);
        } else if (!middle.empty() && num <= *(middle.rbegin())) {
            middle.insert(num);
            sum += num; 
        } else {
            upper.insert(num);
        }
        if (pq.size() == m) {
            // 删除操作
            int remove = pq.front();
            pq.pop();
            auto iter = lower.find(remove);
            auto iter_middle = middle.find(remove);
            auto iter_upper = upper.find(remove);
            if (iter != lower.end()) {
                lower.erase(iter);
            } else if (iter_middle != middle.end()) {
                sum -= *(iter_middle);
                middle.erase(iter_middle);
            } else if (iter_upper != upper.end()) {
                upper.erase(iter_upper);
            }
        }
        // 增加操作
        pq.push(num);
        if (pq.size() == m) {
            while (upper.size() > k) {
                middle.insert(*(upper.begin()));
                sum += *(upper.begin());
                upper.erase(upper.begin());
            }
            while (upper.size() < k) {
                auto iter = middle.end();
                iter--;
                upper.insert(*iter);
                sum -= *(iter);
                middle.erase(iter);
            }
            while (lower.size() > k) {
                auto iter = lower.end();
                iter--;
                middle.insert(*iter);
                sum += *(iter);
                lower.erase(iter);
            }
            while (lower.size() < k) {
                lower.insert(*(middle.begin()));
                sum -= *(middle.begin());
                middle.erase(middle.begin());
            }
        }
    }
    
    int calculateMKAverage() {
        if (pq.size() < m) {
            return -1;
        }
        return sum / (m - k * 2);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
