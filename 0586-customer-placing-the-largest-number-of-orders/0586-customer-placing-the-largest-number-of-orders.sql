# Write your MySQL query statement below
select 
    t.customer_number
from 
    (
        select 
            customer_number,
            count(order_number) as cnt
        from 
            Orders
        group by 
            customer_number
        order by 
            cnt desc
    )t
limit 1;