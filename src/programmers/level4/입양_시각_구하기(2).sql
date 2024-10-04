-- 임시 시간 테이블을 만들어 0시부터 23시까지의 값을 생성
WITH RECURSIVE hours AS (
    SELECT 0 AS hour
    UNION ALL
    SELECT hour + 1 FROM hours WHERE hour < 23
)
SELECT h.hour AS HOUR, 
       COALESCE(COUNT(a.ANIMAL_ID), 0) AS COUNT
FROM hours h
LEFT JOIN ANIMAL_OUTS a
ON h.hour = HOUR(a.DATETIME)  -- MySQL에서 HOUR() 함수 사용
GROUP BY h.hour
ORDER BY h.hour;


-- PostgreSQL
WITH hours AS (
    SELECT generate_series(0, 23) AS hour  -- 0시부터 23시까지의 시간대 생성
)
SELECT h.hour AS HOUR, 
       COALESCE(COUNT(a.ANIMAL_ID), 0) AS COUNT
FROM hours h
LEFT JOIN ANIMAL_OUTS a
ON h.hour = EXTRACT(HOUR FROM a.DATETIME)  -- 입양 시간을 기준으로 시간 추출
GROUP BY h.hour
ORDER BY h.hour;
