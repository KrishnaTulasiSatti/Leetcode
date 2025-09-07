CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      with cte as(
        select dense_rank() over(order by salary desc) as rn,salary
        from employee
      )

      select salary
      from cte
      where rn = N
      limit 1
  );
END