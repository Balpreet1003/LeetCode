-- # Write your MySQL query statement below
select 
    a.book_id, b.title, b.author, b.genre, b.pages, 
    max(a.session_rating) - min(a.session_rating) AS rating_spread, 
    round(SUM(CASE WHEN a.session_rating >= 4 OR a.session_rating <= 2 THEN 1 ELSE 0 END) / COUNT(*), 2) as polarization_score
from 
    reading_sessions as a left join books as b
    on a.book_id=b.book_id
group by
    a.book_id
having
    SUM(CASE WHEN a.session_rating >= 4 THEN 1 ELSE 0 END) > 0 and 
    SUM(CASE WHEN a.session_rating <= 2 THEN 1 ELSE 0 END) > 0 and 
    count(*)>=5 and 
    (SUM(CASE WHEN a.session_rating >= 4 OR a.session_rating <= 2 THEN 1 ELSE 0 END) / COUNT(*)) >= 0.6
order by
    polarization_score DESC,
    b.title DESC;