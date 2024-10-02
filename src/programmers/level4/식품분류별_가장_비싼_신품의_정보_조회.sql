SELECT CATEGORY, PRICE AS MAX_PRICE, PRODUCT_NAME
FROM FOOD_PRODUCT FP
WHERE PRICE = (
    SELECT MAX(PRICE)
    FROM FOOD_PRODUCT
    WHERE CATEGORY = FP.CATEGORY
)
AND CATEGORY IN ('과자', '국', '김치', '식용유')
ORDER BY PRICE DESC;