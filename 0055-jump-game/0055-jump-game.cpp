class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxl=0;
        for(int i=0;i<n;i++){
            if(i>maxl) return false;
            maxl=max(maxl,i+nums[i]);
        }
        return true;
    }
};