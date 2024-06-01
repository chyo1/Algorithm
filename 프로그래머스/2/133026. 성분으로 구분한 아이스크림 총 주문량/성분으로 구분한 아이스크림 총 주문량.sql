-- 코드를 입력하세요
SELECT ingredient_type INGREDIENT_TYPE, SUM(total_order) TOTAL_ORDER
FROM first_half a JOIN icecream_info b ON a.flavor = b.flavor
GROUP BY b.ingredient_type