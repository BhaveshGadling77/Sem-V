-- Alter table

-- create ta table;
CREATE TABLE ta (
	s_id VARCHAR(5),
	course_id VARCHAR(20),
	sec_id VARCHAR(10),
	semester VARCHAR(10),
	year DECIMAL(4,0),

	PRIMARY KEY (s_id, course_id, sec_id, semester, year),
	FOREIGN KEY (s_id) REFERENCES student(ID),
	FOREIGN KEY (course_id, sec_id, semester, year) REFERENCES section(course_id, sec_id, semester, year)
);

-- alter advisors
ALTER TABLE advisor DROP FOREIGN KEY advisor_ibfk_1;
ALTER TABLE advisor MODIFY i_ID VARCHAR(5) NOT NULL, DROP PRIMARY KEY, ADD PRIMARY KEY (s_ID, i_ID);
ALTER TABLE advisor ADD CONSTRAINT fk_advisor_instructor FOREIGN KEY (i_ID) REFERENCES instructor(ID);
INSERT INTO advisor VALUES ('00128', '10101');
insert into advisor values ('00128', '12121');


-- next Query
INSERT INTO instructor (ID, name, dept_name, salary)
VALUES ('99999', 'Ashok', 'Elec. Eng.', 60000);
INSERT INTO advisor (s_ID, i_ID) VALUES
('00128', '10101'),
('00128', '12121'),
('00128', '22222'),
('00128', '15151'),
('00128', '99999'),
('12345', '10101'),
('12345', '99999'),
('23121', '12121'),
('00128', '22222'), 
('23121', '22222');  

-- Q1

SELECT s.ID, s.name, COUNT(*) AS advisor_count
FROM student s
JOIN advisor a ON s.ID = a.s_ID
GROUP BY s.ID, s.name
HAVING COUNT(*) > 3;

-- Q2
INSERT INTO advisor (s_ID, i_ID) VALUES ('12345', '99999');
SELECT s.ID, s.name
FROM student s
JOIN advisor a ON s.ID = a.s_ID
JOIN instructor i ON a.i_ID = i.ID
WHERE i.name IN ('Srinivasan', 'Ashok')
GROUP BY s.ID, s.name
HAVING COUNT(DISTINCT i.name) = 2;

-- Q3
SELECT s.ID, s.name
FROM student s
JOIN advisor a ON s.ID = a.s_ID
JOIN instructor i ON a.i_ID = i.ID
GROUP BY s.ID, s.name
HAVING COUNT(DISTINCT i.dept_name) > 1;

-- Delete queries
DELETE FROM section
WHERE year < 2016;

-- Q2
ALTER TABLE prereq DROP FOREIGN KEY prereq_ibfk_2;
ALTER TABLE prereq ADD CONSTRAINT fk_prereq_course FOREIGN KEY (prereq_id) REFERENCES course(course_id) ON DELETE CASCADE;
SHOW CREATE TABLE prereq;

DELETE FROM course
WHERE course_id = 'CS-101';
--verify
SELECT * 
FROM course
WHERE course_id = 'CS-101';


