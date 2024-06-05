SELECT COUNT(a.fish_type) FISH_COUNT, b.FISH_NAME FISH_NAME
FROM fish_info a JOIN fish_name_info b 
    ON a.fish_type = b.fish_type
GROUP BY b.fish_name
ORDER BY FISH_COUNT desc