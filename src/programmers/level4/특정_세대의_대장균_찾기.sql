WITH RECURSIVE Generation AS (
    -- 1세대 대장균 (PARENT_ID가 NULL)
    SELECT ID, PARENT_ID, 1 AS GenerationLevel
    FROM ECOLI_DATA
    WHERE PARENT_ID IS NULL

    UNION ALL

    -- 재귀적으로 2세대, 3세대를 추적
    SELECT e.ID, e.PARENT_ID, g.GenerationLevel + 1
    FROM ECOLI_DATA e
    JOIN Generation g ON e.PARENT_ID = g.ID
)
-- 3세대 대장균만 출력
SELECT ID
FROM Generation
WHERE GenerationLevel = 3
ORDER BY ID;