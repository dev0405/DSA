class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=INT_MIN;int water=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            water=(min(height[i],height[j]))*(j-i);
            maxWater=max(maxWater,water);
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return maxWater;
    }
};