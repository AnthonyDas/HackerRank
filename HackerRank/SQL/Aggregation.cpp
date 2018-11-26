/*

Revising Aggregations - The Count Function
select count(ID) from CITY where Population > 100000;

Revising Aggregations - The Sum Function
select Sum(Population) from CITY where District = 'California';

Revising Aggregations - Averages
select avg(Population) from CITY where District = 'California';

Average Population
Select round(avg(Population),0) from CITY;

Japan Population
Select sum(Population) from CITY where COUNTRYCODE = 'JPN';

Population Density Difference
Select max(Population) - min(population) from CITY;

The Blunder
select ceil(avg(salary) - avg(replace(salary, '0',''))) from employees;

Top Earners
select max(months * salary), count(name) from employee where (months * salary) in (select max(months * salary) from employee);

Weather Observation Station 2
select round(sum(lat_n),2), round(sum(long_w),2) from Station;

Weather Observation Station 13
Select round(sum(LAT_N),4) from STATION where LAT_N > 38.7880 AND LAT_N < 137.2345;

Weather Observation Station 14
select round(MAX(LAT_N),4) from STATION where LAT_N < 137.2345;

Weather Observation Station 15
Select round(LONG_W,4) from STATION where LAT_N in (select MAX(LAT_N) from STATION where LAT_N < 137.2345);

Weather Observation Station 16
Select round(MIN(LAT_N),4) from STATION where LAT_N > 38.7780;

Weather Observation Station 17
Select round(LONG_W,4) from STATION where LAT_N in (select MIN(LAT_N) from STATION where LAT_N > 38.7780);

Weather Observation Station 18
select round(abs(min(LAT_N) - max(LAT_N)) + abs(min(LONG_W) - max(LONG_W)),4) from STATION;

Weather Observation Station 19
select round(sqrt(POW(min(LAT_N) - max(LAT_N),2) + POW(min(LONG_W) - max(LONG_W),2)),4) from STATION;

Weather Observation Station 20
Select round(s.LAT_N, 4) from Station s where
(select count(LAT_N) from Station where LAT_N < s.LAT_N ) = (select count(LAT_N) from Station where LAT_N > s.LAT_N)

*/