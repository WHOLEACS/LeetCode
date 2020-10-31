class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int,set<int>> mp;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        nums.clear();
        mp.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        bool flag = true;
        if(mp.find(val) != mp.end()) flag = false; 
        mp[val].insert(nums.size()-1);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    //O(1)删除
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int len = nums.size();
        auto it = mp[val].begin();
        if(val == nums[nums.size()-1]) {
            mp[val].erase(mp[val].find(len-1));
        }
        else {
            mp[nums[len-1]].erase(mp[nums[len-1]].find(len-1));
            mp[nums[len-1]].insert((*it));
            swap(nums[len-1],nums[(*it)]);
            mp[val].erase(it);
        }
        if(mp[val].size() == 0) {
            mp.erase(mp.find(val));
        }
        nums.erase(nums.begin()+(len-1));
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        //srand(time(NULL));
        int index = rand()%nums.size();
        return nums[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
