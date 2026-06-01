-- Write your PostgreSQL query statement below
with no_transaction_user as (
    select a.customer_id
    from
        Visits as a
        left join 
        Transactions as b
        on a.visit_id = b.visit_id
    where b.visit_id is null
)

select customer_id, count(*) as count_no_trans
from no_transaction_user
group by customer_id;