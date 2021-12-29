

def solution(roman)
    # complete the solution by transforming the 
    # string roman numeral into an integer
    conv = { 'M' => 1000, 'D' => 500, 'C' => 100, 'L' => 50, 'X' => 10, 'V' => 5, 'I' => 1 }
    p roman.split('').each_with_index.map { |chr, idx| (conv[roman[idx + 1]] || 0) > conv[chr] ? -conv[chr] : conv[chr] }.sum
end

solution("MCMXC")