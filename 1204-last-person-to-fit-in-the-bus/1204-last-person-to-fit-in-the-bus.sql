-- Write your PostgreSQL query statement below
select person_name
from (
    select
        person_name,
        turn,
        sum(weight) over(order by turn) as sum
    from Queue
)
where sum<=1000
order by turn desc
limit 1