/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length!=t.length)
        {
            return false;
        }
        let f1 = new Array(26).fill(0);
        let f2 = new Array(26).fill(0);
        for(let ch of s)
        {
            f1[ch.charCodeAt(0)-97]++;
        }
        for(let ch of t)
        {
            f2[ch.charCodeAt(0)-97]++;
        }
        for(let i=0;i<26;i++)
        {
            if(f1[i]!==f2[i])
            {
                return false;
            }
        }
        return true;
};