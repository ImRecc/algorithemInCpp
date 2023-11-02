//concept are simple, just lick gcd but use "compare" and "whats left"
//to replace the "mod" or "%"
//and repeat the rest..

#include <iostream>
#include <string>

using namespace std;
//otto: I claim your dream
//all this start point are 0, just like before, the goddanm website
//have some bug when compact view...
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //make sure our main string are longer one
        if (str1.length() < str2.length())
        {
            str1.swap(str2);        //we decided to use c++, why swap ourseves?
        } 
        //try to find same, and fiind the same from the rest
       
        if(str2.compare(str1.substr(0, str2.length())) == 0) //java's "equl" are better...
        {
            str1 = str1.substr(str2.length(), (str1.length()-str2.length()) );
            if(str1.length() == 0)  return str2;
                
               
            return gcdOfStrings(str1, str2);
        }
        return "";
    }
};

int main()
{
	string str1 = "ABCABC", str2 = "ABC";
	Solution a;
	string res =a.gcdOfStrings(str1, str2);
	cout << res << endl;
	return 0;
}
