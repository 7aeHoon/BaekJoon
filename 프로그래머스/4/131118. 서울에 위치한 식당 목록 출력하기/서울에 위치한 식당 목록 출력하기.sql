WITH review_avg AS (
    SELECT 
        rest_id, 
        ROUND(AVG(review_score), 2) AS score
    FROM rest_review
    GROUP BY rest_id
)

SELECT 
    ri.rest_id,
    ri.rest_name,
    ri.food_type,
    ri.favorites,
    ri.address,
    ra.score
FROM rest_info ri
    JOIN review_avg ra
        ON ri.rest_id = ra.rest_id
WHERE ri.address LIKE '서울%'
ORDER BY 
    ra.score DESC,
    ri.favorites DESC;
    


