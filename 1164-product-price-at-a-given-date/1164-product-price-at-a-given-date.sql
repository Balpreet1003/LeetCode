# Write your MySQL query statement below
(
    select 
        product_id,
        10 as price
    from 
        Products
    group by product_id
    having min(change_date) > '2019-08-16'
)

union

(
    select
        p.product_id,
        p.new_price
    from
        Products p
        join (
            select 
                product_id,
                max(change_date) as recent_date
            from Products
            where change_date <= '2019-08-16'
            group by product_id
        ) latest
        on p.product_id = latest.product_id and p.change_date = latest.recent_date
)