# Write your MySQL query statement below
select p.product_name,sum(o.unit) as unit
from
Products p
join 
Orders o
on p.product_id = o.product_id
where o.order_date > '2020-01-31' and o.order_date < '2020-03-01'
group by product_name
having unit >= 100;

