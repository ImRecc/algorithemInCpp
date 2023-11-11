>PROGRAM-THINKING

## 1. The increasedTripletSubsequnce.cpp
unlike other find&confirm sequnce mission, find&confirm the order exist first are simply when we don't wanna bruteForce
like:
> ### find the a<b order via
>find the smallest element, and when the second small element shows up,__we catched an a<b order__  <br>
>***no matter how the smallest element changes, we still have info that someone past are smaller than "second small element"*** <br>
>same like the third one, no matter how the 1st small & 2nd small changes, the consequnce are exist <br>
>To return a sequnce, simply record nums when 2nd one changes, who is the 1st small, and when 3rd one shows up, who is the 2nd small

## 2. Is subsequnce.cpp
this find&confirm sequnce mission are quite simple, just keep some principle:
> ### the given request string must be found in order
> which is the order we traverse from 0->max <br>
> so we can simply find if element in main string ***by one iterate*** <br>
> 'cause we iterate array by same order the subsequnce string need <br>
> like: <br>
>  ```find abc in main string
> iterate the string by order and count how many we found, the right answer must be count==lengthOf(abc)```

## 3. Max bucket area.cpp
this pazzle reminds me how to think: find controlable variable, even it decrease through the process...
> no, no bruteForce approach here <br>
> ### find the controlable varies, it's game changing mindset
>``` we get largest width, which is the length, then, nomatter how we change, width just narrow 
> however, path to improvement narrowed to only 

> ***to get improve on area, we can aim on next one higher***
> ``` approach: start from oppsite end, which have largest width
> then, move the smallest end in case to increase the high
> loop it 'till two ends meet
> dont wary about code, just move one by one, a simple finalArea>?nowArea can chose which to record

## 4. counter of A+B=K
this pazzle inspirate me about usage of hashMap<key, value>
> ``` hashMap[i]++, the best way to record i's frequncy, a nice counter
> it's also can be a quick finder to see if have befor

> in this case, we iterator by order, and note that a+b=k, b+a=k too <br>
> so when we meet a, sure hashMap[a]<1, but we could record it like <br>
> **hashMap[a]++;** <br>
> when we meet first b soon, hashMap[k-b]==1, so counter++ <br>
> nice and ez  <br>

## 5. find max average  || 6. slide: count vows via given slider plate
#### 643. Maximum Average Subarray I.cpp || 1456. Maximum Number of Vowels in a Substring of Given Length.cpp
named slide solution
> sum of N nums like a+b+c+d+...y <br>
> but no need to counter every N nums each times <br>
> **record current num, than replace _a to z_ <br>
> sum again, we find other sum 

> same for No.6, slider contain N alpha and count if vows <br>
> then when overSized, check if upPointer are vow, y->substract <br>
> use max() function to manage

## 7. find how many 1 with addtional uno card
#### 1004. Max Consecutive Ones III
clever way in count 0
> p1. uno card way, however, when given k=0, over flip may occur
> p2. reconstructed: counte contiouns 0, <br>
> if overBoard like exceed to k, move upper to validize it <br>
> see more details via code
> ```


