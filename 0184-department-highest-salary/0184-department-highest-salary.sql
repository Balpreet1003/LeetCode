# Write your MySQL query statement below
select 
    t.department as Department,
    t.name as Employee,
    t.salary as Salary
from (
    select 
        a.name, 
        a.salary,
        b.name as department,
        rank() over(partition by b.name order by a.salary desc) as rn
    from 
        Employee as a left join Department as b on a.departmentId = b.id
) t
where rn=1;