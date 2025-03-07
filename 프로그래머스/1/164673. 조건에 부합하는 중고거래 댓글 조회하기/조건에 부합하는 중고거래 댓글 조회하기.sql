-- 코드를 입력하세요
SELECT a.TITLE, A.BOARD_ID, B.REPLY_ID, B.WRITER_ID, B.CONTENTS, DATE_FORMAT(B.CREATED_DATE, '%Y-%m-%d') as CREATED_DATE
from USED_GOODS_BOARD a join USED_GOODS_REPLY b on a.board_id = b.board_id
where year(a.CREATED_DATE) = 2022 and month(a.CREATED_DATE) = 10
order by CREATED_DATE, title