# SELECT *
# FROM food_product
# ORDER BY PRICE DESC
# LIMIT 1;

SELECT * 
FROM food_product
WHERE price = (
    SELECT max(price)
    FROM food_product
);