class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i:nums){
            mp.insert(i);
        }
        int maxSeq=0;
        for(int x:mp){
            if(mp.find(x-1)==mp.end()){
                int curr=x;
                int count=1;
                while(mp.find(curr+1)!=mp.end()){
                    curr++;
                    count++;
                }
                maxSeq=max(maxSeq,count);
            }
        }
        return maxSeq;


    }
};