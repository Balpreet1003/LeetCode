# Write your MySQL query statement below
select
    a.user_id as buyer_id, 
    a.join_date,
    sum(if(year(b.order_date)='2019',1,0)) as orders_in_2019
from
    Users as a left join Orders as b
    on a.user_id=b.buyer_id
group by
    a.user_id;