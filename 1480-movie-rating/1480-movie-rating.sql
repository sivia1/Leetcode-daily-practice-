# Write your MySQL query statement below
(SELECT name as results
FROM MovieRating JOIN Users
using (user_id)
GROUP BY name
ORDER BY COUNT(*) DESC, name limit 1)

UNION ALL

(SELECT title AS results
FROM MovieRating JOIN Movies
using (movie_id)
WHERE date_format(created_at, '%Y-%m') = '2020-02'
GROUP BY title
ORDER BY avg(rating) DESC, title limit 1);