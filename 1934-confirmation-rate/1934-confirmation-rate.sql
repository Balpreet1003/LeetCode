# Write your MySQL query statement below
select 
    a.user_id, 
    ifnull(round(count(case when b.action="confirmed" then 1 end)/count(b.action), 2),0) as confirmation_rate
from 
    Signups as a left join Confirmations as b on a.user_id=b.user_id
group by 
    a.user_id;
