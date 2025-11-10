/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function (nums) {
    let ans = 0;
    let st = [];

    for (let x of nums) {
        while (st.length > 0 && st[st.length - 1] > x) {
            st.pop();
            ans++;
        }

        if (x > 0 && (st.length === 0 || st[st.length - 1] < x)) {
            st.push(x);
        }
    }

    while (st.length > 0) {
        st.pop();
        ans++;
    }

    return ans;
};