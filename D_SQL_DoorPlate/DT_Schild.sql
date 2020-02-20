
-- Raum -> ID, Title
-- Datum -> Start, End (Datetime)
-- Betreff ->  ID, betreff
-- Buchung -> ID, Title

 
IF  NOT EXISTS (SELECT * FROM sys.databases WHERE name = N'DT_Schild')
    BEGIN
        CREATE DATABASE DT_Schild;
    END;


use DT_Schild;

if not exists (select * from sys.tables where name = N'Room')
Begin
create table Room
	(
	R_ID int primary key identity(1 ,1),
	name varchar(60)
	)
end -- end of the Roomtable


Insert into Room values ('Alster')