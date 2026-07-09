class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count = 1;
        int maj=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==maj){
                count++;
            }else{
                count--;
                if(count==0){
                    count=1;
                    maj=nums[i];
                }
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj){
                count++;
            }
        }
        if(count>n/2){
            return maj;
        }else{return -1;}
    }
};