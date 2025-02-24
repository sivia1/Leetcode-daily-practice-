# Write your MySQL query statement below
SELECT 
    EmployeeUNI.unique_id, Employees.name
FROM
    Employees
    #returns all rows from the left table and matching rows from right table
LEFT JOIN
    EmployeeUNI
ON
    Employees.id = EmployeeUNI.id
 