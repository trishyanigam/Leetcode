class Solution {
public:

    bool isPrime(int n)
    {
        if(n < 2)
            return false;

        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        // prime -> all indices divisible by prime
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
        {
            int val = nums[i];

            for(int d = 2; d * d <= val; d++)
            {
                if(val % d == 0)
                {
                    if(isPrime(d))
                        mp[d].push_back(i);

                    while(val % d == 0)
                        val /= d;
                }
            }

            if(val > 1)
                mp[val].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        unordered_set<int> usedPrime;

        while(!q.empty())
        {
            int sz = q.size();

            while(sz--)
            {
                int i = q.front();
                q.pop();

                if(i == n - 1)
                    return steps;

                // i - 1
                if(i - 1 >= 0 && !vis[i - 1])
                {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                // i + 1
                if(i + 1 < n && !vis[i + 1])
                {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                // teleport
                if(isPrime(nums[i]) && !usedPrime.count(nums[i]))
                {
                    int p = nums[i];

                    for(int idx : mp[p])
                    {
                        if(!vis[idx])
                        {
                            vis[idx] = 1;
                            q.push(idx);
                        }
                    }

                    usedPrime.insert(p);
                }
            }

            steps++;
        }

        return -1;
    }
};