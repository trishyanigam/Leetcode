class Solution {
public:
    void merge(int l,int mid,int r,vector<int>&nums)
    {
        int i=l;
        int j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=r)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=r)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=l;k<=r;k++)
        {
            nums[k]=temp[k-l];
        }
    }
    void mergeSort(int l,int r,vector<int>&nums)
    {
        if(l>=r)
        {
            return;
        }

        int mid=(l+r)/2;
        mergeSort(l,mid,nums);
        mergeSort(mid+1,r,nums);
        merge(l,mid,r,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(0,n-1,nums);
        return nums;
    }
};