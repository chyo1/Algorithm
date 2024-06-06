-- 코드를 작성해주세요
SELECT COUNT(FISH_TYPE) AS FISH_COUNT, 
        MAX(CASE WHEN LENGTH IS NULL THEN 10
                ELSE LENGTH END) AS MAX_LENGTH, 
        FISH_TYPE
FROM FISH_INFO
GROUP BY FISH_TYPE
HAVING AVG(CASE WHEN LENGTH IS NULL THEN 10
                ELSE LENGTH END) >= 33
ORDER BY FISH_TYPE ASC