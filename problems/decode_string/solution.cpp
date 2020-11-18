class Solution {
public:
    string decodeString(string s) {
        std::deque<char> m_stack;
        std::deque<char> m_deque;
        std::stack<int> m_digits;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ']') {
                while (std::isalpha(m_stack.back())) {
                    m_deque.push_back(m_stack.back());
                    m_stack.pop_back();
                }
                m_stack.pop_back();
                while (!m_stack.empty() && std::isdigit(m_stack.back())) {
                    m_digits.push(m_stack.back() - '0');
                    m_stack.pop_back();
                }
                
                int k = 0;
                while (!m_digits.empty()) {
                    k = (k * 10) + m_digits.top();
                    m_digits.pop();
                }
                       
                for (int j = 0; j < k; j++) {
                    for (int d = m_deque.size() - 1; d >= 0; d--)
                        m_stack.push_back(m_deque[d]);
                }
                m_deque.clear();
            } else {
                m_stack.push_back(s[i]);
            }
        }
        std::string result(m_stack.begin(), m_stack.end());
        return result;
    }
};