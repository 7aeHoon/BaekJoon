SELECT 
    ai.animal_id AS ANIMAL_ID,
    ai.name AS NAME
FROM animal_ins ai
    INNER JOIN animal_outs ao
        ON ai.animal_id = ao.animal_id
WHERE ai.DATETIME > ao.DATETIME
ORDER BY ai.DATETIME;