class Solution {
public:
    int cnt=0;
    void merge(vector<int>& arr,int l,int m,int h)
    {
        int j=m+1;
        for(int i=l;i<=m;i++)
        {
            while(j<=h && (long long)arr[i]>(2LL)*arr[j])
            {
                j++;
            }
            cnt+=(j-(m+1));
        }
        vector<int> temp;
        int left=l;
        int right=m+1;
        while(left<=m && right<=h)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=m)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=h)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=l;i<=h;i++)
        {
            arr[i] = temp[i-l];
        }
    }
    void mergeSort(vector<int>& arr,int l,int h)
    {
        if(l>=h)
        {
            return;
        }
        int m = (l+h)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,h);
        merge(arr,l,m,h);
    }
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        mergeSort(arr,0,n-1);
        return cnt;
    }
};