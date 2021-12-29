
def order(words)
    # your code...
    words.split(' ').sort! { |a, b| a.delete("^0-9").to_i <=> b.delete("^0-9").to_i }.join(' ')
end

p order("4of Fo1r pe6ople g3ood th5e the2")