-- 코드를 입력하세요
SELECT 
    ai.name AS NAME,
    ai.datetime AS DATETIME
FROM animal_ins ai
WHERE ai.animal_id NOT IN (
    SELECT ao.animal_id
    FROM animal_outs ao
)
ORDER BY datetime
LIMIT 3 OFFSET 0;
