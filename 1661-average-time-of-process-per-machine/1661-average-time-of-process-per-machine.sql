-- Write your PostgreSQL query statement below
select a.machine_id, round(avg(a.timestamp - b.timestamp)::numeric, 3) as processing_time
from 
    Activity as a
    join 
    Activity as b
    on a.machine_id = b.machine_id and a.process_id = b.process_id
where a.activity_type = 'end' and b.activity_type = 'start'
group by a.machine_id;