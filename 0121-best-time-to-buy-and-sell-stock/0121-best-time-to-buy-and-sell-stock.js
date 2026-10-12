/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
        let n = prices.length;
        let mini = Infinity;
        let maxi = -Infinity;
        for(let i=0;i<n;i++)
        {
            mini = Math.min(mini,prices[i]);
            maxi = Math.max(maxi,prices[i]-mini);
        }
        return maxi;
};