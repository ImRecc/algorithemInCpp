//没什么好说的了，如果说p2是巧思那p3就单纯刷熟练度来了
class Solution {
public:
    string reverseWords(string s) {
         int start = 0;
        for (int i = 0; i <= s.length(); i++) { // 
            if (i == s.length() || s[i] == ' ') {
                int end = i - 1;
                while (start < end) {
                    swap(s[start++], s[end--]); //
                }
                start = i + 1;
            }
        }
        return s;
    }
};
