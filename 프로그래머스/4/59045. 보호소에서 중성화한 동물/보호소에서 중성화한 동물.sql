-- 보호소에서 중성화 수술을 거친 동물 정보를 알아보려 합니다. 
-- 보호소에 들어올 당시에는 중성화 되지 않았지만, 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회
-- 아이디 순으로 조회하는 SQL 문을 작성해주세요.

SELECT 
    ai.animal_id, 
    ai.animal_type, 
    ai.name
FROM animal_ins ai
    JOIN animal_outs ao 
        ON ai.animal_id = ao.animal_id
WHERE ai.sex_upon_intake != ao.sex_upon_outcome
ORDER BY ai.animal_id;