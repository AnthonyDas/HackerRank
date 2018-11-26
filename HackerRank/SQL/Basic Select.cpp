/* 

Revising the Select Query I
select * from CITY where COUNTRYCODE = "USA" and POPULATION > 100000;

Revising the Select Query II
select NAME from CITY where COUNTRYCODE = "USA" and POPULATION > 120000;

Select All
select * from CITY;

Select By ID
select * from CITY where ID = 1661;

Japanese Cities' Attributes
select * from CITY where COUNTRYCODE = "JPN";

Japanese Cities' Names
select NAME from CITY where COUNTRYCODE = "JPN";

Weather Observation Station 1
select CITY, STATE from STATION;

Weather Observation Station 3
select distinct CITY from STATION where MOD(ID , 2) = 0;

Weather Observation Station 4
Select count(CITY) - count(distinct CITY) from STATION;

Weather Observation Station 5
Select CITY, CHAR_LENGTH(CITY) from STATION where CHAR_LENGTH(CITY) in (Select MIN(CHAR_LENGTH(CITY)) from STATION) ORDER BY CITY LIMIT 1;
Select CITY, CHAR_LENGTH(CITY) from STATION where CHAR_LENGTH(CITY) in (Select MAX(CHAR_LENGTH(CITY)) from STATION) ORDER BY CITY LIMIT 1;

Weather Observation Station 6
Select distinct CITY from STATION where LEFT(CITY, 1) in ('a', 'e', 'i', 'o', 'u');

Weather Observation Station 7
Select distinct CITY from STATION where RIGHT(CITY, 1) in ('a','e','i','o','u');

Weather Observation Station 8
Select distinct CITY from STATION where LEFT(CITY, 1) in ('a','e','i','o','u') AND RIGHT(CITY, 1) in ('a','e','i','o','u');

Weather Observation Station 9
Select distinct CITY from STATION where LEFT(CITY, 1) NOT IN ('a','e','i','o','u');

Weather Observation Station 10
Select distinct CITY from STATION where RIGHT(CITY, 1) NOT IN ('a','e','i','o','u');

Weather Observation Station 11
select distinct CITY from STATION where LEFT(CITY, 1) NOT IN ('a','e','i','o','u') OR RIGHT(CITY, 1) NOT IN ('a','e','i','o','u');

Weather Observation Station 12
select distinct CITY from STATION where LEFT(CITY, 1) NOT IN ('a','e','i','o','u') AND RIGHT(CITY, 1) NOT IN ('a','e','i','o','u');

Higher Than 75 Marks
Select Name from Students where Marks > 75 Order by RIGHT(NAME, 3), ID

Employee Names
Select name from Employee order by name;

Employee Salaries
Select name from Employee where salary > 2000 AND months < 10 order by employee_id;

*/