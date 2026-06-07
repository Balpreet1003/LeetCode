-- Write your PostgreSQL query statement below
with table1 as (
    select 
    user_id, cnt
    from (
        select 
            user_id,
            count(*) as cnt,
            rank() over (order by count(*) desc) as rnk
        from MovieRating
        group by user_id
    )
    where rnk=1
)

, table2 as (
    select 
        movie_id,
        avg
    from (
        select
            movie_id,
            avg(rating) as avg,
            rank() over (order by avg(rating) desc) as rnk
        from MovieRating
        where to_char(created_at, 'YYYY-MM')='2020-02'
        group by movie_id
    )
    where rnk=1
)

(
    select 
        b.name as results
    from table1 as a
        left join
        Users as b
        on a.user_id=b.user_id
    order by b.name
    limit 1
)

union all

(
    select 
        b.title as results
    from table2 as a
        left join 
        Movies as b
        on a.movie_id=b.movie_id
    order by b.title
    limit 1
)