
str = "Ths website is for losers LOL!"

puts str.slice(0..(str.length)).select { |ch| !"aeiou".include?(ch) }