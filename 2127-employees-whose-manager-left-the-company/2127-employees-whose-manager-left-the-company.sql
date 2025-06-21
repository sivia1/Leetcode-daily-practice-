# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees e
WHERE e.salary < 30000  and e.manager_id not in (SELECT employee_id FROM Employees)
ORDER BY
employee_id
