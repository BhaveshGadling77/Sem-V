-- PART A
-- Q1

SELECT COUNT(*) AS instructors 
FROM instructor WHERE ID NOT IN (
	SELECT ID FROM teaches
);

-- Q2
SELECT building, SUM(capacity) as total_capacity FROM classroom GROUP BY building;

-- Q3

SELECT i.dept_name, COUNT(i.ID) as instructors FROM instructor as i GROUP BY i.dept_name ORDER BY instructors DESC;

-- Q4

SELECT s.ID, s.name, SUM(c.credits) AS total_credits FROM student AS s JOIN takes AS t ON s.ID = t.ID JOIN course AS c ON t.course_id = c.course_id WHERE t.grade IS NOT NULL   AND t.grade <> 'F' GROUP BY s.ID, s.name;

-- PART B
-- Q1
SELECT c.course_id, c.title FROM course AS c WHERE c.course_id NOT IN ( SELECT p.course_id FROM prereq AS p );

-- Q2
SELECT s.name FROM student AS s WHERE s.ID NOT IN ( SELECT t.ID
 FROM takes AS t WHERE t.course_id IN ( SELECT c.course_id
 FROM course AS c  WHERE c.dept_name = 'Biology' ) );

