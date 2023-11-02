//record the word which identified by if(not a space)
//is space? y-> skip n-> record till other space
//we could use hashMap for quick inquire&search
class Solution {
public:
    string reverseWords(string s) {
        unordered_map <int, string> dictionary;     //<key, value>
        int wordCounter=0;
        //record words in hashMap, format: {string, wordCounter}  stored like
        for(int i=0; i<s.length(); i++)
        {            
            if(s[i]!=' ') 
            {
                string buffer;                          //unlike static char[], dont need vector
                while(i<s.length() && s[i] != ' ')      //record to buffer string
                {                                       //stack overflow error just everywhere..
                    buffer += s[i];
                    i++;
                }
                //formated as {string, wordCounter}
                wordCounter++;
                dictionary[wordCounter]=buffer;      
            }  
        }
        //reverse them
        //first to last
        string result;
        for (int i=wordCounter; i>0; i--)
        {
            result+=dictionary.at(i);
            if(i>1) result += ' ';
        } 
        return result;
    }
};
