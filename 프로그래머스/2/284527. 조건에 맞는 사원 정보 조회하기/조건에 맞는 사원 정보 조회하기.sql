SELECT SUM(c.score) SCORE, c.emp_no EMP_NO, b.emp_name EMP_NAME, b.position POSITION, b.email EMAIL
FROM hr_employees b JOIN hr_grade c ON b.emp_no = c.emp_no
GROUP BY c.emp_no
ORDER BY SCORE desc
LIMIT 1