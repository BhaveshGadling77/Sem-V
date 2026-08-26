#Q1

SELECT stcode1, stcode2
FROM track
WHERE distance < 20;

#Q2
SELECT th.id
FROM trainhalts AS th
WHERE th.stcode = (
    SELECT s.stcode
    FROM station AS s
    WHERE s.name = 'Thane'
);

#Q3
SELECT t.name
FROM train AS t
WHERE t.id IN (
    SELECT th.id
    FROM trainhalts AS th
    WHERE th.seqno = 0
      AND th.stcode = (
          SELECT s.stcode
          FROM station AS s
          WHERE s.name = 'MUMBAI'
      )
);

#Q4
SELECT name
FROM station
WHERE stcode IN (
    SELECT th.stcode
    FROM trainhalts AS th
    WHERE th.id = (
        SELECT t.id
        FROM train AS t
        WHERE t.name = 'CST-AMR_LOCAL'
    )
)
ORDER BY (
    SELECT th.seqno
    FROM trainhalts AS th
    WHERE th.stcode = station.stcode
      AND th.id = (
          SELECT t.id
          FROM train AS t
          WHERE t.name = 'CST-AMR_LOCAL'
      )
);
