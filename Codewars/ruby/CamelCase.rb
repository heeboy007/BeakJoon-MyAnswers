def to_camel_case(str)
  result = ""
  is_cap = false
  str.each_char do |letter|
    if letter == '_' || letter == '-'
      is_cap = true
    else
      if is_cap
        result += letter.upcase
      else
        result += letter
      end
      is_cap = false
    end  
  end
  return result
end

example = "the_stealth_warrior"

puts to_camel_case(example)