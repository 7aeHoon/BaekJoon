SELECT I.ingredient_type AS INGREDIENT_TYPE, SUM(F.total_order) AS TOTAL_ORDER
FROM first_half F
INNER JOIN icecream_info I ON F.flavor = I.flavor
GROUP BY INGREDIENT_TYPE
ORDER BY TOTAL_ORDER