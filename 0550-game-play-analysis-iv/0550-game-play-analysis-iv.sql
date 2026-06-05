-- Write your PostgreSQL query statement below
select 
    round(
        count(distinct player_id)::numeric/
        (
            select count(distinct player_id)
            from Activity
        )
    , 2) as fraction

from 
    Activity
where (player_id, event_date-INTERVAL '1 day') in (
    select
        player_id,
        min(event_date) as first_date
    from Activity
    group by player_id
)