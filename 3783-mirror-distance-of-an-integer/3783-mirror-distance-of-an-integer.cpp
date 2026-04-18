class Solution {
public:
    int reverseFunc(int n)
    {
        int rev=0;
        while(n!=0)
        {
            rev=rev*10+n%10;
            n=n/10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int reversedNum = reverseFunc(n);
        return abs(n-reversedNum);
    }
};