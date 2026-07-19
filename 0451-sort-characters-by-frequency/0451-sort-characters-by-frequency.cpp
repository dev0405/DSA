class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> v;

        for(auto it : mp)
            v.push_back({it.first, it.second});

        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        string ans;

        for(int i = 0; i < v.size(); i++)
            ans.append(v[i].second,v[i].first);

        return ans;
    }
};