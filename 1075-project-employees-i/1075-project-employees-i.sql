# Write your MySQL query statement below
select a.project_id, round(sum(b.experience_years)/count(a.project_id), 2) as average_years
from Project as a left join Employee as b
on a.employee_id = b.employee_id
group by a.project_id;