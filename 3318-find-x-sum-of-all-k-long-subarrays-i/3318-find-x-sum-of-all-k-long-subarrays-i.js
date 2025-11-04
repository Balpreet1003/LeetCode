/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findXSum = function(nums, k, x) {
    const n = nums.length;
    const ans = [];

    for (let i = 0; i <= n - k; i++) {
        const sub = nums.slice(i, i + k);
        const freq = new Map();
        for (const num of sub) {
            freq.set(num, (freq.get(num) || 0) + 1);
        }
        const items = Array.from(freq.entries()).sort((a, b) => {
            if (a[1] === b[1]) return b[0] - a[0];
            return b[1] - a[1];
        });
        const topX = new Set();
        for (let j = 0; j < items.length && j < x; j++) {
            topX.add(items[j][0]);
        }
        let xSum = 0;
        for (const num of sub) {
            if (topX.has(num)) xSum += num;
        }
        ans.push(xSum);
    }

    return ans;
};