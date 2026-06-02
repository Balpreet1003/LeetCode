-- Write your PostgreSQL query statement below
with student_table2 as (
    select 
        a.student_id,
        b.subject_name,
        a.student_name
    from
        Students as a
        cross join
        Subjects as b
)

select
    a.student_id,
    a.student_name,
    a.subject_name,
    count(b.student_id) as attended_exams
from
    student_table2 as a
    left join
    Examinations as b
    on a.student_id = b.student_id and a.subject_name = b.subject_name
group by
    a.student_id,
    a.subject_name,
    a.student_name
order by
    a.student_id,
    a.student_name;