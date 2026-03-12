-- 코드를 입력하세요
SELECT b.category AS CATEGORY, SUM(sales) AS TOTAL_SALES
FROM book b
INNER JOIN book_sales s ON b.book_id = s.book_id
WHERE DATE_FORMAT(s.sales_date, '%Y-%m') = "2022-01"
GROUP BY CATEGORY
ORDER BY CATEGORY;