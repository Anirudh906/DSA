CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT(SALARY) from EMPLOYEE e1 where 
        N-1 = (SELECT COUNT(DISTINCT SALARY)from EMPLOYEE e2 where e2.SALARY > e1.SALARY)
  );
END