# Write your MySQL query statement below
SELECT c.name AS country FROM person p JOIN country c ON 
SUBSTRING(phone_number, 1, 3) = c.country_code JOIN calls AS ca 
ON p.id IN (ca.caller_id, ca.callee_id) GROUP BY c.name HAVING AVG(duration) > (SELECT AVG(duration) FROM calls);