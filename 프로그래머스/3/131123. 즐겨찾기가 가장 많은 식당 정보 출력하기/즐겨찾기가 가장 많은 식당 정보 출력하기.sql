-- 코드를 입력하세요
SELECT
    i.food_type,
    i.rest_id,
    i.rest_name,
    i.favorites
FROM rest_info i
    JOIN (
        SELECT
            food_type,
            MAX(FAVORITES) AS max_favorites
        FROM rest_info
        GROUP BY food_type
) f
    ON i.food_type = f.food_type
    AND i.favorites = f.max_favorites
ORDER BY i.food_type DESC;