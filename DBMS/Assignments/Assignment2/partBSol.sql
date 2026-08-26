-- Q1
SELECT c.course_id, c.title FROM course AS c WHERE c.course_id NOT IN ( SELECT p.course_id FROM prereq AS p );

-- Q2
SELECT s.name FROM student AS s WHERE s.ID NOT IN ( SELECT t.ID
 FROM takes AS t WHERE t.course_id IN ( SELECT c.course_id
 FROM course AS c  WHERE c.dept_name = 'Biology' ) );


