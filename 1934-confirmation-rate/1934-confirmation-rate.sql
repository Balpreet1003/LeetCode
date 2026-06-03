-- Write your PostgreSQL query statement below
select 
    a.user_id,
    round(
        avg(
            CASE
                WHEN b.action = 'confirmed' THEN 1.0
                ELSE 0.0
            END
        ), 2
    ) as confirmation_rate
from
    Signups as a
    left join
    Confirmations as b
    on a.user_id = b.user_id
group by
    a.user_id