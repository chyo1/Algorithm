SELECT a.item_id ITEM_ID, a.item_name ITEM_NAME 
FROM item_info a JOIN item_tree b ON a.item_id = b.item_id
WHERE b.parent_item_id is null
ORDER BY ITEM_ID asc