
def find_even_index(arr)
    # your code here
    arr.length.times { |split| return split if arr[0..split].sum == arr[split..arr.length].sum }
    return -1
end

p find_even_index([1,2,3,2,1])
p find_even_index([1,2,3,4,5,6])
p find_even_index([20,10,-80,10,10,15,35])
p find_even_index(Array(1..100))
