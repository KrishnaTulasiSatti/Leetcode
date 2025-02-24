# Write your MySQL query statement below
with cte as
(select d.name as dep,e.name as name,e.salary as salary,rank() over(partition by d.name order by salary desc) as rank1
from
employee e
join
department d
on e.departmentId = d.id)

select dep as Department,name as Employee,salary as Salary
from cte
where rank1 = 1;