//mind-changing pazzle too
//visit https://github.com/ImRecc/algorithemInCpp/tree/main/uncommonDataDealing#readme
//p3 for details...

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size(), pointerLeft=0, pointerRight=size-1;
        int area=0, finalArea=0;
        while(pointerLeft<pointerRight)
        {
            if(height[pointerLeft]<height[pointerRight])
            {
                area=height[pointerLeft]*(pointerRight-pointerLeft);
                pointerLeft++;
            }
            else
            {
                area=height[pointerRight]*(pointerRight-pointerLeft);
                pointerRight--;
            }
            if (area>finalArea) finalArea = area;
        }
        return finalArea;
        
    }
};
