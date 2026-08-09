#Q1
SELECT stcode1, stcode2 FROM track WHERE distance<20;

#Q2
SELECT id FROM trainhalts as th JOIN station as s ON s.stcode=th.stcode where s.name='Thane';

#Q3
SELECT t.name FROM train as t JOIN trainhalts th ON t.id=th.id JOIN station as s ON th.stcode=s.stcode WHERE th.seqno=0 AND s.name='MUMBAI';

#Q4
SELECT st.name FROM trainhalts AS th JOIN  station AS st ON st.stcode=th.stcode WHERE id = (SELECT t.id FROM train AS t WHERE t.name = 'CST-AMR_LOCAL'
) ORDER BY seqno;
