//char dictionary, store vowlews' position
//like [0, 2, 3, 8]
//note that usage of vector<type> vectorName;
class Solution {
public:
    string reverseVowels(string s) {
        //store all vowels and their position
        vector<int> vowStr;
        string vowDic = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int timer = 0;
        
        for (int i=0; i<s.length(); i++)
        {   //simple vow verify&record
            if(vowDic.find(s[i]) != string::npos) //strange symbol
            {   
                vowStr.push_back(i); 
                timer++;
            }  
        }
        //reverse them
        //first to last
        for (int i=0; i<timer/2; i++)
        {
            swap(s[vowStr.at(i)], s[vowStr.at(timer-i-1)]);   
        }  
        
        return s;
    
    }
};
