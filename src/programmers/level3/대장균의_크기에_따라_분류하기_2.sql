-- 코드를 작성해주세요
WITH RankedColony AS (
    SELECT ID, SIZE_OF_COLONY,
           NTILE(4) OVER (ORDER BY SIZE_OF_COLONY DESC) AS rank_group
    FROM ECOLI_DATA
)
SELECT ID,
       CASE
           WHEN rank_group = 1 THEN 'CRITICAL'
           WHEN rank_group = 2 THEN 'HIGH'
           WHEN rank_group = 3 THEN 'MEDIUM'
           ELSE 'LOW'
       END AS COLONY_NAME
FROM RankedColony
ORDER BY ID;