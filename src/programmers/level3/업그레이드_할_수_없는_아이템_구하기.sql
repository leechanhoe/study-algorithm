-- 코드를 작성해주세요
SELECT f.ITEM_ID, f.ITEM_NAME, f.RARITY
FROM ITEM_INFO f JOIN ITEM_TREE t ON f.ITEM_ID = t.ITEM_ID
WHERE f.ITEM_ID NOT IN (
    SELECT PARENT_ITEM_ID
    FROM ITEM_TREE 
    WHERE PARENT_ITEM_ID IS NOT NULL)
ORDER BY f.ITEM_ID DESC