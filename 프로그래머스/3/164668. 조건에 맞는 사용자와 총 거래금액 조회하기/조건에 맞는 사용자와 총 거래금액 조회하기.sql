-- 코드를 입력하세요
SELECT u.user_id, u.nickname, SUM(b.price) AS total_sales
FROM used_goods_board b
JOIN used_goods_user u ON b.writer_id = u.user_id
WHERE b.status = 'DONE'
GROUP BY u.user_id
HAVING total_sales >= 700000
ORDER BY total_sales;