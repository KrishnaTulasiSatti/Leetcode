# Write your MySQL query statement below
select actor_id,director_id
from ActorDirector as a
group by actor_id,director_id
having count(a.timestamp) >= 3;

