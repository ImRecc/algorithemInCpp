//duo pointer
//downPointer: 1.activity find elment
class Solution {
public:
    int maxVowels(string s, int k) {
    unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};
    int upPointer = 0, lowPointer = 0;
    int maxVowels = 0, currentVowels = 0;
    int length=s.length();
    while (lowPointer < length) 
    {
        if (vowelsSet.count(s[lowPointer]) > 0) //a set like <key, equal2Key>
        {
            currentVowels++;       //see if is a vowel
        }

        if (lowPointer - upPointer + 1 > k) //like 3->1 are 3long but 3-1=2 so plus1
        {
            if (vowelsSet.count(s[upPointer]) > 0)  //when slide oversize, if counted, then substrac
            {
                currentVowels--;
            }
            upPointer++;            //move begin of slider
        }
        //smart way to iterate every k'long array on a slide
        //each time, check if *upPointer==vow, are reducing the overCount from previousK'slider
        //and slide beginPoint smart way

        maxVowels = max(maxVowels, currentVowels);
        lowPointer++;
    }
    return maxVowels;
}
};
