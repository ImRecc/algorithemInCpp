//just a double pointer, not fun at all
class Solution{
public:
int compress(vector<char>& chars) {
	int recorder = 0;
	for(int readPoint = 1, count = 1; readPoint <= chars.size(); readPoint++, count++) 
    	{
	    //note that recorder only use for record, and reader only compare with itself's past
	    //there are seperated
		if(readPoint == chars.size() || chars[readPoint] != chars[readPoint - 1]) 
        	{
			chars[recorder++] = chars[readPoint - 1];       //note that char[r]=char[rp-1] r++  
			if(count >= 2) 
				for(char digit : to_string(count)) 
					chars[recorder++] = digit;
			count = 0;
		}
	}
	return recorder;		//the recorder also play as "the last one standed"
	//we don't do any clearance 'cause only display and exam the first(recorder) number of the vector;
    }
};
