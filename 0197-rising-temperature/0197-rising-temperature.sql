-- Write your PostgreSQL query statement below
select a.id
from
    Weather as a
    join
    Weather as b
    ON a.recordDate = b.recordDate + interval '1 day'
where a.temperature > b.temperature;