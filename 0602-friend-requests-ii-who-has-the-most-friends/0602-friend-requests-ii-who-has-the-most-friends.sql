-- Write your PostgreSQL query statement below
with table1 as (
    select 
        requester_id as id,
        count(*) as cnt
    from RequestAccepted
    group by requester_id

    union all

    select 
        accepter_id as id,
        count(*) as cnt
    from RequestAccepted
    group by accepter_id
)

select 
    id,
    sum(cnt) as num
from table1
group by id
order by num desc
limit 1