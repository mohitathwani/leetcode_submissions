class Solution {
public:
    vector<vector<string> > result;
    map<string, vector<string> >prefixMap;
    int col = 0;
    
    vector<string> wordsWithPrefix(vector<string>& words, string prefix) {
        if (prefix.empty()) return words;
        return prefixMap[prefix];
    }
    
    void backtrack(vector<string>& words, vector<string>& tempList, string prefix, int wordSize) {
        if (col == wordSize) {
            result.push_back(tempList);
            return;
        }
        
        vector<string> prefixedWords = wordsWithPrefix(words, prefix);
        for(int i = 0; i < prefixedWords.size(); i++) {
            string curWord = prefixedWords[i];
            tempList.push_back(curWord);
            col++;
            prefix.clear();
            for(int j = 0; j < tempList.size(); j++) {
                prefix.push_back(tempList[j][col]);
            }
            backtrack(words, tempList, prefix, wordSize);
            prefix.pop_back();
            col--;
            tempList.pop_back();
        }
        
    }
    
    void buildPrefixMap(vector<string>& words) {
        for(int i = 0; i < words.size(); i++) {
            for(int j = 1; j <= words[i].size(); j++) {
                string prefix = words[i].substr(0, j);
                if(prefixMap.count(prefix) == 0) {
                    prefixMap[prefix] = vector<string>();
                }
                prefixMap[prefix].push_back(words[i]);
            }
        }
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (!words.empty()) {
            buildPrefixMap(words);
            vector<string> tempList;
            int wordSize = words[0].size();
            if (wordSize == 1) {
                result.push_back(words);
            } else {
                backtrack(words, tempList, "", wordSize);
            }
        }
        return result;
    }
};