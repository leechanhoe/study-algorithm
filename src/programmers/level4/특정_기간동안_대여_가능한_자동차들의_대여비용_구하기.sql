SELECT C.CAR_ID as CAR_ID, -- 자동차 ID
       C.CAR_TYPE as CAR_TYPE, -- 자동차 종류
       -- 대여료 x 30일 x 내야할 비율 = 요금
       -- (100 - 할인률)/100 = 내야할 비율
       ROUND(C.DAILY_FEE*30*(100-P.DISCOUNT_RATE)/100) AS FEE -- 지불 비용
    FROM CAR_RENTAL_COMPANY_CAR C
            -- C가 각각 연결될 수 있기 때문에 C를 기준으로 나머지 두 테이블을 연결한다.
            JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY H ON C.CAR_ID = H.CAR_ID -- CAR_ID기준으로
            JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN P ON C.CAR_TYPE = P.CAR_TYPE -- CAR_TYPE기준으로
            
    -- 대여 가능한 2022-11-01 ~ 2022-12-01에 대여가 가능한 자동차를 목록을 가져와야하므로 
    -- NOT IN을 써서 해당 기간에 렌탈 기록이 없는 CAR_ID를 가져와야 한다
    WHERE C.CAR_ID NOT IN ( 
        SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE END_DATE >= '2022-11-01' AND START_DATE <= '2022-12-01'
        
) AND P.DURATION_TYPE like '30%' -- 그리고 대여 기간이 30일 이상인 것을 검색해야하므로
GROUP BY C.CAR_ID -- 자동차 ID 기준으로 그룹화하여
HAVING C.CAR_TYPE IN ('세단', 'SUV') -- 자동차 종류가 세단과 SUV인 것만
    AND (FEE >= 500000 AND FEE < 2000000) -- 30일간의 대여 금액이 50만원 200만원 미만인 자동차 
ORDER BY FEE DESC, CAR_TYPE, CAR_ID DESC