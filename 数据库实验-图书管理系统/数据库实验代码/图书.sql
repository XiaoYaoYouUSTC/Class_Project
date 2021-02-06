create table PB18000051book(
	IBSN varchar(20) not null unique,
	����� varchar(20) not null unique,
	���� varchar(20) not null,
	���� varchar(20) not null,
	���� varchar(20) not null,
	������ varchar(20)not null,
	������� int not null,
	�۸� float not null,
	������� int not null,
	ʣ������ int not null constraint book51_check1 check (ʣ������>=0),
	constraint book51_pk primary key(IBSN),
 	constraint book51_check2 check(�������>=ʣ������)
)
insert into PB18000051book values('7-03-009402-6','O441-44/2','���ѧǧ���','������','��֮��','��ѧ������',2002,48.00,4,4)
insert into PB18000051book values('978-7-04-020849-8','O3-43/3(5��','��ѧ�����','������','�ʵ�','�ߵȽ���������',2007,35.00,2,2)
insert into PB18000051book values('978-7-5366-9293-0','I247.55/44','����','��ѧ��','������','���������',2008,23.00,1,1)
insert into PB18000051book values('7-111-18777-6','TP301.6/18','�㷨����','���Ӽ������','����','��е��ҵ������',2006,85.00,2,2)
insert into PB18000051book values('978-7-301-21612-5','O156.1/1(3)','��������','��ѧ��','�˳ж�','������ѧ������',2013,48.00,3,3)
create table PB18000051student(
	ѧ���� varchar(12) not null unique,
	���� varchar(10) not null,
	�ѽ���Ŀ int not null constraint stu51_che1 check(�ѽ���Ŀ>=0),
	���� varchar(20)not null,
	���� varchar(10) not null constraint stu51_che2 check(���� in ('����Ա','��ͨ�û�')),
	constraint stu51_pk primary key(ѧ����)
)
insert into PB18000051student values('PB18000021','����',0,'12345','��ͨ�û�')
insert into PB18000051student values('PB18210071','����',0,'54321','��ͨ�û�')
insert into PB18000051student values('AB12345678','admin',0,'admin','����Ա')
create table PB18000051specificbook(
	IBSN varchar(20) not null,
	����� varchar(10) not null unique,
	ѧ���� varchar(12),
	����ʱ�� datetime,
	Ӧ��ʱ�� datetime,
	�Ƿ�黹 varchar(3) constraint spec51_check1 check(�Ƿ�黹 in ('��','��')),
	constraint spec51_pk primary key(�����),
	constraint spec51_fk1 foreign key(IBSN) references PB18000051book(IBSN),
	constraint spec51_fk2 foreign key(ѧ����) references PB18000051student(ѧ����)
)
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('7-03-009402-6','0000000001','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('7-03-009402-6','0000000002','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('7-03-009402-6','0000000003','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('7-03-009402-6','0000000004','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('978-7-04-020849-8','0000000005','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('978-7-04-020849-8','0000000006','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('978-7-5366-9293-0','0000000007','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('7-111-18777-6','0000000008','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('7-111-18777-6','0000000009','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('978-7-301-21612-5','0000000010','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('978-7-301-21612-5','0000000011','��')
insert into PB18000051specificbook(IBSN,�����,�Ƿ�黹) values('978-7-301-21612-5','0000000012','��')
create table PB18000051buy(
	�ɹ��� varchar(15) not null unique,
	IBSN varchar(20) not null,
	���� datetime not null,
	�ɹ����� int not null constraint buy51_che1 check(�ɹ�����>=1),
	���� float not null constraint buy51_che2 check(����>=0),
	�ɹ�ԭ�� varchar(100),
	constraint buy51_pk primary key(�ɹ���),
	constraint buy51_fk foreign key(IBSN) references PB18000051book(IBSN)
)
create table PB18000051elim(
	��̭�� varchar(15) not null unique,
	IBSN varchar(20) not null,
	����� varchar(10) not null unique, 
	���� datetime not null,
	��̭ԭ�� varchar(100),
	constraint elim51_pk primary key(��̭��),
	constraint elim51_fk foreign key(IBSN) references PB18000051book(IBSN)
)
