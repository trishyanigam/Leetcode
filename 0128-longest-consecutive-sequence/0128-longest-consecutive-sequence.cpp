class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;
        for(int n:st)
        {
            if(st.find(n-1)==st.end())
            {
                int curr = n;
                int cnt=1;
                while(st.find(curr+1)!=st.end())
                {
                    curr++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};