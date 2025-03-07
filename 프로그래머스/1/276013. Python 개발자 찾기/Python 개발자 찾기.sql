select ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPER_INFOS
WHERE 'Python' in (skill_1, skill_2, skill_3)
order by id