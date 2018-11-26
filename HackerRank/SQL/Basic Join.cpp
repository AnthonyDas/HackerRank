/*

Asian Population
select sum(population) from CITY where CountryCode in (select code from COUNTRY where Continent = 'Asia');

African Cities
select name from CITY where CountryCode in (select code from COUNTRY where Continent = 'Africa');

Average Population of Each Continent
select a.continent, floor(avg(b.population)) from COUNTRY a, city b where b.CountryCode = a.code group by a.continent;

Top Competitors
select h.hacker_id, h.name from hackers h
inner join submissions s on h.hacker_id = s.hacker_id
inner join challenges c on s.challenge_id = c.challenge_id
inner join difficulty d on c.difficulty_level = d.difficulty_level
where s.score = d.score
group by h.hacker_id, h.name
having count(s.hacker_id) > 1
order by count(s.hacker_id) desc, s.hacker_id asc;

Ollivander's Inventory
select w.id, p.age, w.coins_needed, w.power from Wands w
inner join Wands_Property p on w.code = p.code
inner join
	(select p.age, min(w.coins_needed) as min_price, w.power from Wands w
	inner join Wands_Property p on w.code = p.code
	where p.is_evil = 0
	group by p.age, w.power) m
on p.age = m.age and w.coins_needed = m.min_price and w.power = m.power
order by w.power desc, p.age desc;

Challenges
select h.hacker_id, h.name, count(c.challenge_id) as c_count
from Hackers h,  Challenges c
where h.hacker_id = c.hacker_id
group by h.hacker_id, h.name
having c_count =
	(select count(*) as counts1 from Challenges group by hacker_id order by counts1 desc limit 1)
or c_count in
	(select temp.counts2 from
		(select count(challenge_id) as counts2 from Challenges group by hacker_id) temp
	group by temp.counts2
	having count(temp.counts2) = 1)
order by c_count desc, h.hacker_id;

Contest Leaderboard




*/