# Write your MySQL query statement below
select customers
from
(select c.name as customers,o.customerId as customerId
from Customers c
left join Orders o
on c.id = o.customerId) as subquery
where customerId is NULL;