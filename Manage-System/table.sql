CREATE TABLE test (
  str VARCHAR(20) DEFAULT NULL
) 
INSERT INTO test VALUE('scuess');

---###############################

CREATE TABLE t_account(
id 	VARCHAR(20)  NOT NULL PRIMARY KEY,
PASSWORD VARCHAR(40) NOT NULL DEFAULT '123456',
NAME 	VARCHAR(30)  NOT NULL DEFAULT 'unset',
TYPE 	VARCHAR(10)  NOT NULL
);
ALTER TABLE t_account ADD CHECK(TYPE IN ('student','teacher','manager'));

INSERT INTO t_account(id,NAME,TYPE)VALUES('1234560','xianjin','manager');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234561','docker','student');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234562','nginx','student');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234563','jenkins','student');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234564','linux','student');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234565','windows','student');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234566','unicode','student');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234567','utf8','teacher');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234568','mysql','teacher');
INSERT INTO t_account(id,NAME,TYPE)VALUES('1234569','postgres','teacher');

---###############################

CREATE TABLE t_course (
  id VARCHAR (20) NOT NULL PRIMARY KEY,
  NAME VARCHAR (30) NOT NULL DEFAULT 'unset',
  teacherid VARCHAR (20) NOT NULL DEFAULT 'unset'
) 

INSERT INTO t_course (id,NAME,teacherid) VALUES('00001','math','1234567');
INSERT INTO t_course (id,NAME,teacherid) VALUES('00002','program','1234567');
INSERT INTO t_course (id,NAME,teacherid) VALUES('00003','history','1234568');
INSERT INTO t_course (id,NAME,teacherid) VALUES('00004','english','1234568');
INSERT INTO t_course (id,NAME,teacherid) VALUES('00005','chinese','1234569');

---###############################

CREATE TABLE t_grade (
  course_id VARCHAR (20) NOT NULL,
  student_id VARCHAR (20) NOT NULL,
  grade DOUBLE DEFAULT 0
) 

INSERT INTO t_grade(course_id,student_id,grade)VALUES('00001','1234561',88);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00001','1234562',99.3);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00001','1234563',55.4);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00001','1234564',77.6);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00001','1234565',45);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00001','1234566',76);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00002','1234561',78);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00002','1234562',78);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00002','1234564',78);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00003','1234563',78);
INSERT INTO t_grade(course_id,student_id,grade)VALUES('00003','1234565',78);
---###############################

CREATE TABLE t_select (
  stdid VARCHAR (20) NOT NULL,
  courid VARCHAR (20) NOT NULL
) 

INSERT INTO t_select(stdid,courid)VALUES('1234561','00001');
INSERT INTO t_select(stdid,courid)VALUES('1234562','00001');
INSERT INTO t_select(stdid,courid)VALUES('1234563','00001');
INSERT INTO t_select(stdid,courid)VALUES('1234564','00001');
INSERT INTO t_select(stdid,courid)VALUES('1234565','00001');
INSERT INTO t_select(stdid,courid)VALUES('1234566','00001');
INSERT INTO t_select(stdid,courid)VALUES('1234561','00002');
INSERT INTO t_select(stdid,courid)VALUES('1234561','00001');
INSERT INTO t_select(stdid,courid)VALUES('1234562','00002 ');
INSERT INTO t_select(stdid,courid)VALUES('1234564','00002');
INSERT INTO t_select(stdid,courid)VALUES('1234564','00003');
INSERT INTO t_select(stdid,courid)VALUES('1234565','00003');
INSERT INTO t_select(stdid,courid)VALUES('1234563','00003');
INSERT INTO t_select(stdid,courid)VALUES('1234561','00003');

