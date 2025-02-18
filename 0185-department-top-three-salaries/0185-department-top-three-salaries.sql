# Write your MySQL query statement below

with cte as 
(select e.name as emp_name,e.salary as emp_salary,d.name as dept_name,
dense_rank() over(partition by d.id order by e.salary desc) as rank1
from
Employee e
join
Department d
on e.departmentId = d.id)
select dept_name as Department,emp_name as Employee,emp_salary as Salary
from 
cte
where rank1 < 4
order by emp_salary;
