//1.leave edge along
//2.find out all triple 0 and counter +=1
//3.check out if brink are double 0 if so +=1
//however ,still cant figure the brink..
//so we leave brink along instead to a 0, and abanded find triple 000 to a directly path
//it's fine to set another data structure、 array, we are here to slove and try for time complexity
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //we created a new bed which embody brink as 0
        int rawSize = flowerbed.size(), bed1Size=rawSize+2;
        int bed1[bed1Size]; 
        bed1[0]=0, bed1[bed1Size-1]=0;
        for (int i=0; i<rawSize; i++) bed1[i+1]=flowerbed[i];
        
        //once triple 0 found, we insert a flower and counter += 1;
        int counter=0;
        for (int i=1; i<bed1Size-1; i++)
        {
            if(bed1[i-1]==0 && bed1[i]==0 && bed1[i+1]==0)  
            //dunnon why 1==2==3 failed, language feature..
            {                                       
                counter++;
                bed1[i]=1;
            }
        }
        return (counter >= n);
    }
};
