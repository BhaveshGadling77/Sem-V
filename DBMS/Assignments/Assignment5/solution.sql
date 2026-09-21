
-- Q1
ALTER TABLE trainhalts
      ADD CONSTRAINT chk_time
      CHECK (timein <= timeout)

-- Q2

ALTER TABLE trainhalts ADD CONSTRAINT fk_trainhalts_train FOREIGN KEY (id) REFERENCES train(id) ON DELETE CASCADE;

INSERT INTO train VALUES ('T20', 'Mahrashtra Express');

INSERT INTO trainhalts (id, seqno, stcode, timein, timeout) VALUES
('T20', 999, 'PUNE', '12:00', '13:00');

DELETE FROM train WHERE id = ‘T20’

-- 	Q3
INSERT INTO trainhalts
(id, seqno, stcode, timein, timeout)
VALUES
('T1', 999, 'PUNE', '12:00', '10:00');

INSERT INTO trainhalts (id, seqno, stcode, timein, timeout) 
values ('T1', 999, 'Pune', '12:00', '1300');

DELETE FROM train WHERE id = 'T1';

select * from trainhalts where id = 'T1';


-- create table statements
CREATE TABLE remotecentre (
    centreId INT PRIMARY KEY,
    college VARCHAR(100) NOT NULL,
    town VARCHAR(50),
    state VARCHAR(50)
);

CREATE TABLE person (
    ID INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE
);

CREATE TABLE programme (
    progId INT PRIMARY KEY,
    title VARCHAR(100) NOT NULL,
    fromdate DATE,
    todate DATE,
    CHECK (fromdate <= todate)
);

CREATE TABLE coordinator (
    ID INT,
    progId INT,
    centreId INT,

    PRIMARY KEY (ID, progId, centreId),

    FOREIGN KEY (ID)
        REFERENCES person(ID),

    FOREIGN KEY (progId)
        REFERENCES programme(progId),

    FOREIGN KEY (centreId)
        REFERENCES remotecentre(centreId)
);

CREATE TABLE participant (
    ID INT,
    progId INT,
    centreId INT,

    PRIMARY KEY (ID, progId, centreId),

    FOREIGN KEY (ID)
        REFERENCES person(ID),

    FOREIGN KEY (progId)
        REFERENCES programme(progId),

    FOREIGN KEY (centreId)
        REFERENCES remotecentre(centreId)
);


