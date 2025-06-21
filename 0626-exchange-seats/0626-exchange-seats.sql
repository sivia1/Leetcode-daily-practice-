# Write your MySQL query statement below
#use ORDER BY, CASE, COALESCE to keep the last student in their original seat if no adjacent seat is available
SELECT
    CASE when id%2 = 0 then id-1
    when id%2 != 0 and id=(select max(id) from Seat) then id
    when id%2 != 0 then id+1
    end as id,
    student
FROM Seat 
ORDER BY id
