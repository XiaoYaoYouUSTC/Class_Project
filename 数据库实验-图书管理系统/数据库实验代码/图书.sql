create table PB18000051book(
	IBSN varchar(20) not null unique,
	索书号 varchar(20) not null unique,
	书名 varchar(20) not null,
	类型 varchar(20) not null,
	作者 varchar(20) not null,
	出版社 varchar(20)not null,
	出版年份 int not null,
	价格 float not null,
	库存数量 int not null,
	剩余数量 int not null constraint book51_check1 check (剩余数量>=0),
	constraint book51_pk primary key(IBSN),
 	constraint book51_check2 check(库存数量>=剩余数量)
)
insert into PB18000051book values('7-03-009402-6','O441-44/2','电磁学千题解','物理类','张之翔','科学出版社',2002,48.00,4,4)
insert into PB18000051book values('978-7-04-020849-8','O3-43/3(5）','力学第五版','物理类','朗道','高等教育出版社',2007,35.00,2,2)
insert into PB18000051book values('978-7-5366-9293-0','I247.55/44','三体','文学类','刘慈欣','重庆出版社',2008,23.00,1,1)
insert into PB18000051book values('7-111-18777-6','TP301.6/18','算法导论','电子计算机类','科曼','机械工业出版社',2006,85.00,2,2)
insert into PB18000051book values('978-7-301-21612-5','O156.1/1(3)','初等数论','数学类','潘承洞','北京大学出版社',2013,48.00,3,3)
create table PB18000051student(
	学工号 varchar(12) not null unique,
	姓名 varchar(10) not null,
	已借数目 int not null constraint stu51_che1 check(已借数目>=0),
	密码 varchar(20)not null,
	级别 varchar(10) not null constraint stu51_che2 check(级别 in ('管理员','普通用户')),
	constraint stu51_pk primary key(学工号)
)
insert into PB18000051student values('PB18000021','张三',0,'12345','普通用户')
insert into PB18000051student values('PB18210071','李四',0,'54321','普通用户')
insert into PB18000051student values('AB12345678','admin',0,'admin','管理员')
create table PB18000051specificbook(
	IBSN varchar(20) not null,
	条码号 varchar(10) not null unique,
	学工号 varchar(12),
	借阅时间 datetime,
	应还时间 datetime,
	是否归还 varchar(3) constraint spec51_check1 check(是否归还 in ('是','否')),
	constraint spec51_pk primary key(条码号),
	constraint spec51_fk1 foreign key(IBSN) references PB18000051book(IBSN),
	constraint spec51_fk2 foreign key(学工号) references PB18000051student(学工号)
)
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('7-03-009402-6','0000000001','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('7-03-009402-6','0000000002','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('7-03-009402-6','0000000003','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('7-03-009402-6','0000000004','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('978-7-04-020849-8','0000000005','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('978-7-04-020849-8','0000000006','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('978-7-5366-9293-0','0000000007','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('7-111-18777-6','0000000008','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('7-111-18777-6','0000000009','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('978-7-301-21612-5','0000000010','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('978-7-301-21612-5','0000000011','是')
insert into PB18000051specificbook(IBSN,条码号,是否归还) values('978-7-301-21612-5','0000000012','是')
create table PB18000051buy(
	采购号 varchar(15) not null unique,
	IBSN varchar(20) not null,
	日期 datetime not null,
	采购数量 int not null constraint buy51_che1 check(采购数量>=1),
	单价 float not null constraint buy51_che2 check(单价>=0),
	采购原因 varchar(100),
	constraint buy51_pk primary key(采购号),
	constraint buy51_fk foreign key(IBSN) references PB18000051book(IBSN)
)
create table PB18000051elim(
	淘汰号 varchar(15) not null unique,
	IBSN varchar(20) not null,
	条码号 varchar(10) not null unique, 
	日期 datetime not null,
	淘汰原因 varchar(100),
	constraint elim51_pk primary key(淘汰号),
	constraint elim51_fk foreign key(IBSN) references PB18000051book(IBSN)
)
