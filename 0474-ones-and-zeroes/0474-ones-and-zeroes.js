/**
 * @param {string[]} strs
 * @param {number} m
 * @param {number} n
 * @return {number}
 */

let getCount = function (s) {
    let zeros = 0, ones = 0;
    for (let c of s) {
        if (c === '0') zeros++;
        else if (c === '1') ones++;
    }
    return [zeros, ones];
};

var findMaxForm = function (strs, m, n) {
    const dp = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

    for (const s of strs) {
        const [z, o] = getCount(s);

        for (let i = m; i >= z; i--) {
            for (let j = n; j >= o; j--) {
                dp[i][j] = Math.max(dp[i][j], 1 + dp[i - z][j - o]);
            }
        }
    }

    return dp[m][n];
};