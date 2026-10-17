class Solution {
public:
    int majorityElement(vector<int>& nums) {
        stack<int> st;
        for(int num:nums){
            if(st.empty()){
                st.push(num);
            }else if(num==st.top()){
                st.push(num);
            }else{
                st.pop();
            }
        }
        return st.top();
    }
};