SELECT FI.ID, FNI.FISH_NAME, FI.LENGTH
FROM
    FISH_INFO FI
JOIN
    FISH_NAME_INFO FNI ON FI.FISH_TYPE = FNI.FISH_TYPE
JOIN
    (SELECT FISH_TYPE, MAX(LENGTH) AS MAX_LENGTH
     FROM FISH_INFO
     GROUP BY FISH_TYPE) MAX_FI
    ON FI.FISH_TYPE = MAX_FI.FISH_TYPE AND FI.LENGTH = MAX_FI.MAX_LENGTH
ORDER BY
    FI.ID;