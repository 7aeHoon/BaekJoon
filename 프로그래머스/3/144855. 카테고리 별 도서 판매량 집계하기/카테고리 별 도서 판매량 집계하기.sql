SELECT 
    b.category AS CATEGORY,
    SUM(sales) AS TOTAL_SALES
FROM book b INNER JOIN book_sales bs 
    ON b.book_id = bs.book_id
WHERE DATE_FORMAT(bs.sales_date, '%Y-%m')  = '2022-01'
GROUP BY CATEGORY
ORDER BY CATEGORY;