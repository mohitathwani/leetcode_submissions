class Solution {
public:
    bool isStrobogrammatic(string num) {
        map<char, char> transformations;
        transformations['0'] = '0';
        transformations['1'] = '1';
        transformations['6'] = '9';
        transformations['8'] = '8';
        transformations['9'] = '6';
        
        if (num.size() > 1 && (num.back() == '0' || num.front() == '0')) {
            return false;
        }
        
        deque<char> temp;
        for (int i = 0; i < num.size(); i++) {
            char o = num[i];
            if (transformations.count(o) == 1) {
                temp.push_front(transformations[o]);
            } else {
                return false;
            }
        }
        
        string result(temp.begin(), temp.end());
        
        return result == num;
    }
};