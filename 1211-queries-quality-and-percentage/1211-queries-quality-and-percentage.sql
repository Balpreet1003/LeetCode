-- Write your PostgreSQL query statement below
select
    query_name,
    round(avg(rating::numeric/position::numeric), 2) as quality,
    round(100*count(*)filter(where rating < 3)::numeric/count(*), 2) as poor_query_percentage
from
    Queries
group by
    query_name
