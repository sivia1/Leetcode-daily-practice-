# Write your MySQL query statement below
SELECT teacher_id, COUNT(DISTINCT subject_id) as cnt
FROM Teacher 
GROUP BY teacher_id;
# GROUP BY teacher_id creates groups:

-- Group 1: All rows where teacher_id = 1
-- Group 2: All rows where teacher_id = 2


-- For teacher_id = 1:

-- subject_ids in this group: [2, 2, 3]
-- COUNT(DISTINCT subject_id) → COUNT(DISTINCT [2, 2, 3]) → COUNT([2, 3]) → 2


-- For teacher_id = 2:

-- subject_ids in this group: [1, 2, 3, 4]
-- COUNT(DISTINCT subject_id) → COUNT([1, 2, 3, 4]) → 4