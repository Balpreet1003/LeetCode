WITH first_login AS (
    SELECT player_id,
           MIN(event_date) OVER (PARTITION BY player_id) AS first_date,
           event_date
    FROM Activity
),
next_day_login AS (
    SELECT DISTINCT player_id
    FROM first_login
    WHERE event_date = DATE_ADD(first_date, INTERVAL 1 DAY)
)
SELECT 
    ROUND(
        COUNT(DISTINCT n.player_id) * 1.0 / COUNT(DISTINCT a.player_id),
        2
    ) AS fraction
FROM Activity a
LEFT JOIN next_day_login n 
    ON a.player_id = n.player_id;