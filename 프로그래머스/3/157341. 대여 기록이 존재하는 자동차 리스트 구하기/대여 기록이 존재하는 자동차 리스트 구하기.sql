-- 자동차 종류가 '세단'인 자동차들 중 10월에 대여를 시작한 기록이 있는 자동차 ID 리스트를 출력
-- 자동차 ID 리스트는 중복이 없어야 하며, 자동차 ID를 기준으로 내림차순 정렬
# SELECT *
# FROM car_rental_company_car
# WHERE car_type = '세단';

SELECT DISTINCT(cc.car_id)
FROM car_rental_company_car cc
    JOIN car_rental_company_rental_history cr
        ON cc.car_id = cr.car_id
WHERE cc.car_type = '세단' AND DATE_FORMAT(cr.start_date, '%Y-%m') = '2022-10'
ORDER BY cc.car_id DESC;


# SELECT DISTINCT(car_id)
# FROM car_rental_company_rental_history
# WHERE DATE_FORMAT(start_date, '%Y-%m') = '2022-10';