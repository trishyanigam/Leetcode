/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    let res = [];
    function dfs(curr,d)
    {
        for(let x of curr)
        {
            if(Array.isArray(x) && d>0)
            {
                dfs(x,d-1);
            }
            else
            {
                res.push(x);
            }
        }
    }
    dfs(arr,n);
    return res;
};