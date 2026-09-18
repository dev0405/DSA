class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> res;
        sort(a.begin(),a.end());
        res.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            vector<int>& last=res.back();
            if(last[1]>=a[i][0]){
                last[1]=max(last[1],a[i][1]);
            }else{
                res.push_back(a[i]);
            }
        }
        return res;
    }
};