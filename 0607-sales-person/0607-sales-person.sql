# Write your MySQL query statement below
select 
    distinct a.name
from 
    SalesPerson as a 
where a.sales_id not in( 
    select a.sales_id
    from Orders as a join Company as b on a.com_id=b.com_id
    where b.name='RED'
);
