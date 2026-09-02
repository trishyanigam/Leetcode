class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = 0;
        int even = 0;
        for(int x:nums1)
        {
            if(x%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        if(odd==n || (odd>=1 && even>=1) || even==n)
        {
            return true;
        }
        return false;
    }
};