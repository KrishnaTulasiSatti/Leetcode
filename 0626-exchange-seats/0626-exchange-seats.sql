select id,
case 
   when id % 2 != 0 then lead(student,1,student) over(order by id)
   else lag(student,1,student) over(order by id)
end as student
from Seat;