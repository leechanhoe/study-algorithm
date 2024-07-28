-- 첫 번째 CTE: 2022년 8월부터 10월까지의 자동차별 총 대여 횟수를 계산하고 5회 이상인 자동차만 선택
WITH TotalRentals AS (
    SELECT
        CAR_ID,
        COUNT(*) AS TOTAL_RECORDS
    FROM
        CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE
        START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
    GROUP BY
        CAR_ID
    HAVING
        COUNT(*) >= 5
),
-- 두 번째 CTE: 월별로 자동차별 대여 횟수를 계산
MonthlyRentals AS (
    SELECT
        MONTH(START_DATE) AS MONTH,
        CAR_ID,
        COUNT(*) AS RECORDS
    FROM
        CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE
        START_DATE BETWEEN '2022-08-01' AND '2022-10-31'
        AND CAR_ID IN (SELECT CAR_ID FROM TotalRentals)
    GROUP BY
        MONTH,
        CAR_ID
)
-- 최종 결과 선택 및 정렬
SELECT
    MONTH,
    CAR_ID,
    RECORDS
FROM
    MonthlyRentals
ORDER BY
    MONTH,
    CAR_ID DESC;