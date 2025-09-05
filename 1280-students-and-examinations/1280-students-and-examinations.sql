# Write your MySQL query statement below
select a.student_id, a.student_name, c.subject_name, 
    count(b.subject_name) as attended_exams
from Students as a cross join Subjects as c left join Examinations as b
on a.student_id=b.student_id and b.subject_name=c.subject_name
group by a.student_id, a.student_name, c.subject_name
order by a.student_id, c.subject_name;
