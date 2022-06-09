//https://leetcode.com/problems/group-anagrams/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int> , vector<int>> mpm;
        
        int n = strs.size();
        for(int i=0;i<n;i++){
            int m = strs[i].size();
            map<char,int> mp;
            for(int j=0;j<m;j++){
                mp[strs[i][j]]++;
            }
            mpm[mp].push_back(i+1);
        }
        vector<vector<string>> sol(mpm.size());
        int x=0;
        for (auto itr : mpm){
            for(auto i : itr.second){
                sol[x].push_back(strs[i-1]);
            }
            x++;
        }
        return sol;
    }