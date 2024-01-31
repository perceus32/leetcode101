class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        bool equalBroken = false;
        vector<int> res;
        for (int i : asteroids) {
            if (s.empty() && i < 0) {
                res.push_back(i);
            } else if (i > 0) {
                s.push(i);
            } else {
                while (!s.empty() && s.top() < abs(i)) {
                    s.pop();
                }
                if (!s.empty() && s.top() == abs(i)) {
                    s.pop();
                    continue;
                } else if (!s.empty() && s.top() > abs(i)) {
                    continue;
                }
                res.push_back(i);
            }
        }
        int n = res.size();
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin() + n, res.end());
        return res;
    }
};