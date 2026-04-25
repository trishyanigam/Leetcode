class Solution {
public:
    int getNext(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=((n%10)*(n%10));
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1 && !seen.count(n))
        {
            seen.insert(n);
            n = getNext(n);
        }
        return n==1;
    }
};