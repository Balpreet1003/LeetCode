# Write your MySQL query statement below
select 
    Products.product_name,
    sum(Orders.unit) as unit
from
    Products join Orders on Products.product_id=Orders.product_id
where 
    order_date >= '2020-02-01' and order_date<='2020-02-29'
group by
    Orders.product_id
having
    sum(Orders.unit)>=100