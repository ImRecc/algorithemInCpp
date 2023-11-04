>PROGRAM-THINKING

# 1. The increasedTripletSubsequnce.cpp
unlike other find&confirm sequnce mission, find&confirm the order exist first are simply when we don't wanna bruteForce
like:
> # find the a<b order via
>find the smallest element, and when the second small element shows up,__we catched an a<b order__  <br>
>***no matter how the smallest element changes, we still have info that someone past are smaller than "second small element"*** <br>
>same like the third one, no matter how the 1st small & 2nd small changes, the consequnce are exist <br>
>To return a sequnce, simply record nums when 2nd one changes, who is the 1st small, and when 3rd one shows up, who is the 2nd small

# 2. Is subsequnce.cpp
this find&confirm sequnce mission are quite simple, just keep some principle:
> # the given request string must be found in order
> which is the order we traverse from 0->max <br>
> so we can simply find if element in main string ***by one iterate*** <br>
> 'cause we iterate array by same order the subsequnce string need <br>
> like: <br>
>  ```find abc in main string
> iterate the string by order and count how many we found, the right answer must be count==lengthOf(abc)```
