#Q1
SELECT name
FROM student
WHERE tot_cred > 100;

#Q2
SELECT t.course_id, t.grade
FROM takes AS t
WHERE t.ID = (
    SELECT s.ID
    FROM student AS s
    WHERE s.name = 'Tanaka'
);

#Q3
SELECT c.course_id, c.title
FROM course AS c
WHERE c.course_id IN (
    SELECT s.course_id
    FROM section AS s
    WHERE s.semester = 'Fall'
)
AND c.course_id IN (
    SELECT s.course_id
    FROM section AS s
    WHERE s.semester = 'Spring'
);

#Q4
SELECT name
FROM instructor
WHERE dept_name = 'Comp. Sci.';

#Q5
SELECT c.course_id, c.title
FROM course AS c
WHERE c.course_id IN (
    SELECT t.course_id
    FROM teaches AS t
    WHERE t.ID = (
        SELECT i.ID
        FROM instructor AS i
        WHERE i.name = 'Srinivasan'
    )
);

#Q6 
SELECT DISTINCT name
FROM instructor
WHERE ID IN (
    SELECT t.ID
    FROM teaches AS t
    WHERE t.semester = 'Spring'
      AND t.year = 2009
);
