/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} guards
 * @param {number[][]} walls
 * @return {number}
 */
var countUnguarded = function(n, m, guards, walls) {
    // Initialize grid with '.'
    let grid = Array.from({ length: n }, () => Array(m).fill('.'));

    // Place walls
    for (let [x, y] of walls) {
        grid[x][y] = 'W';
    }

    // Place guards
    for (let [x, y] of guards) {
        grid[x][y] = 'G';
    }

    // Initially unguarded cells = total cells - (guards + walls)
    let ans = n * m - (guards.length + walls.length);

    // Track guarded cells
    let trace = Array.from({ length: n }, () => Array(m).fill(false));

    for (let [x, y] of guards) {
        // Left direction
        for (let j = y - 1; j >= 0; j--) {
            if (trace[x][j]) continue;
            if (grid[x][j] === 'W' || grid[x][j] === 'G') break;
            trace[x][j] = true;
            ans--;
        }

        // Right direction
        for (let j = y + 1; j < m; j++) {
            if (trace[x][j]) continue;
            if (grid[x][j] === 'W' || grid[x][j] === 'G') break;
            trace[x][j] = true;
            ans--;
        }

        // Up direction
        for (let i = x - 1; i >= 0; i--) {
            if (trace[i][y]) continue;
            if (grid[i][y] === 'W' || grid[i][y] === 'G') break;
            trace[i][y] = true;
            ans--;
        }

        // Down direction
        for (let i = x + 1; i < n; i++) {
            if (trace[i][y]) continue;
            if (grid[i][y] === 'W' || grid[i][y] === 'G') break;
            trace[i][y] = true;
            ans--;
        }
    }

    return ans;
};
