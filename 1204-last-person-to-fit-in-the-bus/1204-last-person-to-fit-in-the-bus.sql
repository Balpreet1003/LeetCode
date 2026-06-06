-- Write your PostgreSQL query statement below
select a.person_name
from Queue as a inner join Queue as b
on a.turn >= b.turn
group by a.turn, a.person_name
having sum(b.weight)<=1000
order by sum(b.weight) desc
limit 1;