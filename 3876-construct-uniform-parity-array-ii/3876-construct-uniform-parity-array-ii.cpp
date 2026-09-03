class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd = 0;
        // int mini = nums1[0];
        int miniOdd = 2e9;
        for(int x:nums1){
            if(x % 2 != 0){
                odd++;
                // miniOdd = min(miniOdd,x);
            }
            miniOdd = min(miniOdd,x);
        }
        bool canBeEven = (odd == 0);
        bool canBeOdd = (miniOdd%2 != 0);
        return canBeEven || canBeOdd;
    }
};