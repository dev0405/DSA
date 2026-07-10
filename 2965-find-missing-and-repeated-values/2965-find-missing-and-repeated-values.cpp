class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a,b;
        int n=grid.size();
        vector<int> ans;
        unordered_set<int> s;
        int expSum=(n*n)*(n*n+1)/2;
        int actSum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actSum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    ans.push_back(grid[i][j]);
                    a=grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }
        b=expSum+a-actSum;
        ans.push_back(b);
        return ans;
    }
};