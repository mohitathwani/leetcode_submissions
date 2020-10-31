class Solution {
public:
    typedef map<char, vector<string>> DigitMap;
    vector<string> recurse(const char* digits, size_t size, DigitMap& digitMap) {
        if (size == 1) {
            return digitMap[digits[0]];
        }
        
        vector<string> subResult = recurse(digits + 1, size - 1, digitMap);
        vector<string> result;
        vector<string> letters = digitMap[digits[0]];
        for (int i = 0; i < letters.size(); i++) {
            stringstream ss;
            for (int j = 0; j < subResult.size(); j++) {
                ss << letters[i];
                ss << subResult[j];
                result.push_back(ss.str());
                ss.str("");
            }
        }
        
        return result;
    }
    
    vector<string> letterCombinations(string digits) {
        DigitMap digitMap;
        digitMap['2'] = {"a", "b", "c"};
        digitMap['3'] = {"d", "e", "f"};
        digitMap['4'] = {"g", "h", "i"};
        digitMap['5'] = {"j", "k", "l"};
        digitMap['6'] = {"m", "n", "o"};
        digitMap['7'] = {"p", "q", "r", "s"};
        digitMap['8'] = {"t", "u", "v"};
        digitMap['9'] = {"w", "x", "y", "z"};
        
        if (digits.empty()) {
            return vector<string>();
        }
        
        return recurse(digits.c_str(), digits.size(), digitMap);
    }
};