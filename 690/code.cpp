/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    // dfs 递归：返回值 调用单元 终止条件
    void dfs(unordered_map<int, int>& mp, const vector<Employee*>& employees, int id, int& solve) {
        solve += employees[mp[id]]->importance;
        for (int i = 0; i < employees[mp[id]]->subordinates.size(); i++) {
            dfs(mp, employees, employees[mp[id]]->subordinates[i], solve);
        }
        return;
    }

    int getImportance(vector<Employee*> employees, int id) {
        int solve = 0;
        unordered_map<int, int> mp;
        mp.clear();
        for (int i = 0; i < employees.size(); i++) {
            mp[employees[i]->id] = i;
        }
        dfs(mp, employees, id, solve);
        return solve;
    }
};
