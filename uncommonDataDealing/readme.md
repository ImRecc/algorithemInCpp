>PROGRAM-THINKING
>
# 1. The increasedTripletSubsequnce.cpp
unlike other find&confirm sequnce mission, find&confirm the order exist first are simply when we don't wanna bruteForce
like:
 1.find the a<b order via
>find the smallest element, and when the second small element shows up, we catched a order
>no matter how the smallest element changes, we still have info that someone past are smaller than "second small element"
>same like the third one, no matter how the 1st small & 2nd small changes, the consequnce are exist
>
>To return a sequnce, simply record nums when 2nd one changes, who is the 1st small, and when 3rd one shows up, who is the 2nd small
