SELECT animal_id, name,
CASE
    WHEN SEX_UPON_INTAKE LIKE 'Neutered%' THEN 'O'
    WHEN SEX_UPON_INTAKE LIKE 'Spayed%' THEN 'O'
    ELSE 'X'
END AS '중성화'
FROM animal_ins
ORDER BY animal_id;