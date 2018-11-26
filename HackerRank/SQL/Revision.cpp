/*

select * from TABLE where FIELD1 = "USA" and FIELD2 > 100000;

select distinct CITY from STATION where MOD(ID , 2) = 0;

Select count(CITY) - count(distinct CITY) from STATION;

Select CITY, CHAR_LENGTH(CITY) from STATION where CHAR_LENGTH(CITY) in (Select MIN(CHAR_LENGTH(CITY)) from STATION)
ORDER BY CITY LIMIT 1;

Select distinct CITY from STATION where LEFT(CITY, 1) in ('a', 'e', 'i', 'o', 'u');

Select distinct CITY from STATION where RIGHT(CITY, 1) in ('a','e','i','o','u');

Select distinct CITY from STATION where LEFT(CITY, 1) NOT IN ('a','e','i','o','u');

select count(ID) from CITY where Population > 100000;

select Sum(Population) from CITY where District = 'California';

select avg(Population) from CITY where District = 'California';

Select round(avg(Population), 0) from CITY;

Select max(Population) - min(population) from CITY;

select ceil(avg(salary) - avg(replace(salary, '0',''))) from employees;

select round(sqrt(POW(min(LAT_N) - max(LAT_N),2) + POW(min(LONG_W) - max(LONG_W),2)),4) from STATION;

*/