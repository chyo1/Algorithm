-- 코드를 입력하세요
SELECT a.book_id BOOK_ID, b.author_name AUTHOR_NAME, DATE_FORMAT(a.published_date, '%Y-%m-%d') PUBLISHED_DATE
FROM book a JOIN author b ON a.author_id = b.author_id
WHERE a.category = "경제"
ORDER BY PUBLISHED_DATE ASC