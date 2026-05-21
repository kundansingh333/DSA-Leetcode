# Write your MySQL query statement below
select e.name 
from Employee e 
inner join Employee ep on e.id=ep.managerId
group by e.name,e.id
having count(ep.id)>=5;

