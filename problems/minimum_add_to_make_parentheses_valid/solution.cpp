class Solution {
public:
    int minAddToMakeValid(string text) {
        int extraOpen = 0;
        int extraClose = 0;
  
        for (int i =0; i < text.size(); i++) {
             if (text[i] == '(') {
                extraOpen++;
    }
    
    if (text[i] == ')') {
      if (extraOpen > 0) {
        extraOpen--;
      } else {
        extraClose++;
      }
      
    }
  }
  
  return extraOpen + extraClose;
    }
};