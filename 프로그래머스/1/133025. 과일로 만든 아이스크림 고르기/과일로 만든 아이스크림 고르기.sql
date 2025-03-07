-- 코드를 입력하세요
SELECT a.flavor as FLAVOR
from first_half a join icecream_info b on a.flavor = b.flavor
where b.ingredient_type = 'fruit_based' and a.total_order > 3000
order by a.total_order desc