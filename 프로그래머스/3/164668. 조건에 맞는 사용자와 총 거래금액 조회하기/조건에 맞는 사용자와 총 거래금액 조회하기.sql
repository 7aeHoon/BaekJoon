-- 완료된 중고 거래의 총금액이 70만 원 이상인 사람의 회원 ID, 닉네임, 총거래금액을 조회
-- 결과는 총거래금액을 기준으로 오름차순 정렬
SELECT u.user_id, u.nickname, SUM(price) AS total_sales
FROM used_goods_board b
    JOIN used_goods_user u
        ON b.writer_id = u.user_id
WHERE b.status = 'done'
GROUP BY u.user_id
HAVING total_sales >= 700000
ORDER BY total_sales;