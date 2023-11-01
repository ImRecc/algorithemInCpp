// idk this even could be a quest in leetcode..
// just like some EXPUNKS intro level to make sure people know how a prog work
// without thread controls
class Solution{
public:
	string mergeAlternately(string word1, string word2)
	{
		string tango1;
		for (int i=0; i<max(word1.length(), word2.length()); i++)
		{
			if (i < word1.length())
			{
				tango1 += word1[i];
			}
			if (i < word2.length())
			{
				tango1 += word2[i];
			}
		}
		// just like two EXPUNK bugs start with sequnce and seizing the chars 
		return tango1;
	}
};
