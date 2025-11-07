/**
 * @param {number[]} stations
 * @param {number} r
 * @param {number} k
 * @return {number}
 */
var maxPower = function(stations, r, k) {
    const n = stations.length;
    const diff = new Array(n).fill(0n);
    const ll = BigInt;

    for (let i = 0; i < n; i++) {
        diff[Math.max(0, i - r)] += BigInt(stations[i]);
        if (i + r + 1 < n)
            diff[i + r + 1] -= BigInt(stations[i]);
    }

    const isPossible = (tar) => {
        let x = 0n, curr_k = BigInt(k);
        const temp = [...diff];

        for (let i = 0; i < n; i++) {
            x += temp[i];
            if (x < tar) {
                const add = tar - x;
                if (add > curr_k) return false;
                curr_k -= add;
                x += add;
                if (i + 2 * r + 1 < n)
                    temp[i + 2 * r + 1] -= add;
            }
        }
        return true;
    };

    let l = diff.reduce((a, b) => (a < b ? a : b), diff[0]);
    let h = stations.reduce((a, b) => a + BigInt(b), 0n) + BigInt(k);
    let ans = -1n;

    while (l <= h) {
        const mid = (l + h) / 2n;
        if (isPossible(mid)) {
            ans = mid;
            l = mid + 1n;
        } else {
            h = mid - 1n;
        }
    }
    return Number(ans);
};