#Q1
SELECT name FROM student WHERE tot_cred>100; 

#Q2
SELECT t.course_id, t.grade FROM takes as t join student as s on s.ID=t.ID WHERE s.name='Tanaka';

#Q3
SELECT c.course_id, c.title FROM course c JOIN section s ON c.course_id
= s.course_id WHERE s.semester IN ('Fall', 'Spring') GROUP BY c.course_id, c.title HAVING COUNT(DISTINCT s.semester) = 2;

#Q4
SELECT name FROM instructor WHERE dept_name='Comp. Sci.';

#Q5
SELECT c.course_id,c.title FROM course as c JOIN teaches as t On c.course_id=t.course_id JOIN instructor as i ON i.ID=t.ID WHERE i.name='Srinivasan';

#Q6
SELECT DISTINCT i.name FROM instructor as i JOIN teaches as t ON i.ID=t.ID WHERE t.semester='Spring' AND t.year=2009;

