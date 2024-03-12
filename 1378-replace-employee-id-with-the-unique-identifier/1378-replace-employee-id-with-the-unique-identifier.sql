# Write your MySQL query statement below
select empuni.unique_id,Employees.name from EmployeeUNI as empuni 
  right join Employees on  Employees.id=empuni.id; 