-- 코드를 입력하세요
SELECT a.PRODUCT_CODE, SUM(a.price * b.sales_amount) SALES
FROM product a JOIN offline_sale b ON a.product_id = b.product_id
GROUP BY a.product_id
ORDER BY SALES DESC, a.product_code asc