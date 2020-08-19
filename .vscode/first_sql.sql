SELECT last_name, first_name, dept_no
from employees, dept_emp
WHERE employees.emp_no=dept_emp.emp_no


SELECT  em.last_name,em.first_name,de.dept_no
FROM employees em
Left join dept_emp de
on em.emp_no=de.emp_no

SELECT sa.emp_no,sa.salary
FROM employees em
join salaries sa
where em.emp_no=sa.emp_no
AND em.hire_date=sa.from_date
order by em.emp_no DESC

SELECT emp_no, count(emp_no) as t
FROM salaries
GROUP BY emp_no HAVING t>15


SELECT DISTINCT salary 
FROM salaries
WHERE to_date='9999-01-01'
ORDER by salary DESC


SELECT de.dept_no, de.emp_no,sa.salary
FROM dept_manager de,salaries sa
WHERE de.emp_no=sa.emp_no
and de.to_date=sa.to_date
and de.to_date='9999-01-01'


SELECT em.emp_no
FROM employees em
JOIN dept_manager de
WHERE NOT em.emp_no=de.emp_no

SELECT emp_no FROM employees
WHERE emp_no NOT IN (SELECT emp_no from dept_manager)


SELECT emp_no FROM employees
EXCEPT
SELECT emp_no FROM dept_manager

SELECT employees.emp_no FROM employees left JOIN dept_manager
on employees.emp_no=dept_manager.emp_no
WHERE dept_no is NULL


SELECT de.emp_no, dm.emp_no as manager_no 
from dept_emp de, dept_manager dm
WHERE dm.to_date='9999-01-01' 
and de.emp_no<>dm.emp_no 
and de.dept_no=dm.dept_no

SELECT de.dept_no,sa.emp_no,max(sa.salary) as salary
FROM dept_emp de,salaries sa
WHERE de.emp_no=sa.emp_no


