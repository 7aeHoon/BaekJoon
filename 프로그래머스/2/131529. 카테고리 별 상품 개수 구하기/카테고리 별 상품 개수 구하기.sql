SELECT LEFT(product_code, 2) AS CATEGORY, COUNT(*) AS PRODUCTS
FROM product
GROUP BY LEFT(product_code, 2)
ORDER BY product_code;