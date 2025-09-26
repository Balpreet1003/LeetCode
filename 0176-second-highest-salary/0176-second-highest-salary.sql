# Write your MySQL query statement below
SELECT 
    CASE 
        WHEN COUNT(*) = 0 THEN NULL
        ELSE salary
    END AS SecondHighestSalary
FROM (
    SELECT salary,
           DENSE_RANK() OVER (ORDER BY salary DESC) AS rnk
    FROM Employee
) t
WHERE rnk = 2;