class Solution {
public:
    bool isPermutation(string s1,string word)
    {
        int arr[26] = {0};
        for(char c:s1)
        {
            arr[c-'a']++;
        }
        for(char c:word)
        {
            arr[c-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2)
        {
            return false;
        }
        for(int i=0;i<=n2-n1;i++)
        {
            string word;
            word=s2.substr(i,n1);
            if(isPermutation(s1,word))
            {
                return true;
            }
        }
        return false;
    }
};