//funny quest funny solution
//we traverse entire main string _WITH ORDER_
//and record how many we found in main string
//counter == pattern long? ok!

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int patternCounter=0;
        for(int i=0; i<t.length(); i++)
        {
            if(s[patternCounter]==t[i])
            {
                patternCounter++;
            }
        }
        if(patternCounter!=s.length()) return false;
        else return true;
        
    }
};
