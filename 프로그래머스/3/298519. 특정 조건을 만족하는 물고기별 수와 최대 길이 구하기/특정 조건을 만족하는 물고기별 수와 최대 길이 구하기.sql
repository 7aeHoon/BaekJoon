WITH new_fish_info AS (
    SELECT
        id,
        fish_type,
        IFNULL(length, 10) AS length
    FROM fish_info
)

SELECT
    COUNT(fish_type) AS fish_count,
    MAX(length) AS max_length,
    fish_type
FROM new_fish_info
GROUP BY fish_type
HAVING AVG(length) >= 33
ORDER BY fish_type;
    

