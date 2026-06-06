-- Write your PostgreSQL query statement below
select
    a.employee_id, 
    a.name,
    count(b.reports_to) as reports_count,
    round(avg(b.age)) as average_age
from
    Employees as a
    join 
    Employees as b
    on a.employee_id = b.reports_to and b.reports_to is not null
group by 
    a.employee_id, 
    a.name
order by
    a.employee_id