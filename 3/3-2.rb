
$lins = []
loop do
  inp = gets.chomp
  break if inp == "-1"
  $lins << inp
end
$nums = []
$cnt = []
$lins.length.times {
  |i|
  tmp = []
  tmp2 = []
  $lins[0].length.times {
    |j|
    tmp << 1
    tmp2 << 0
  }
  $nums << tmp
  $cnt << tmp2
}
      
 
def extract(str)
  num = 0
  str.length.times {
    |i|
    if str[i] =~ /\A\d\z/
      num = num * 10 + str[i].to_i
    else
      break
    end
  }
  return num
end

def calc(i, j, num)
  if $lins[i][j] == '*'
    $nums[i][j] *= num
    $cnt[i][j] += 1
  end
end

i = 0
j = 0
ans = 0
tot = 0
loop do 
    j = 0
    loop do 
      if j >= $lins[i].length
        break
      end
     if $lins[i][j] =~ /\A\d\z/
        num = extract($lins[i][j..-1])
        tot += num
        if i > 0
          if j > 0
            if $lins[i-1][j-1] != '.' and not $lins[i-1][j-1] =~ /\A\d\z/
              calc(i-1,j-1,num) 
              j = j + num.to_s.length
              next
            end
          end
          if j + num.to_s.length <= $lins[i].length - 1
            if $lins[i-1][j+num.to_s.length] != '.' and not $lins[i-1][j+num.to_s.length] =~ /\A\d\z/
              calc(i-1, j+num.to_s.length, num)
              j = j + num.to_s.length
              next
            end
          end
          if $lins[i-1][j..j+num.to_s.length-1] != '.' * num.to_s.length
            k = j
            loop do
              calc(i-1, k, num)
              k += 1
              break if k >= j+num.to_s.length
            end
            j = j + num.to_s.length
            next
          end
        end
        if i < $lins.length - 1
          if j > 0
            if $lins[i+1][j-1] != '.' and not $lins[i+1][j-1] =~ /\A\d\z/
              calc(i+1, j-1, num)
              j = j + num.to_s.length
              next
            end
          end
          if j + num.to_s.length <= $lins[i].length - 1
            if $lins[i+1][j+num.to_s.length] != '.' and not ($lins[i+1][j+num.to_s.length] =~ /\A\d\z/)
              calc(i+1, j+num.to_s.length, num)
              j = j + num.to_s.length
              next
            end
          end
          if $lins[i+1][j..j+num.to_s.length-1] != '.' * num.to_s.length
            k = j
            loop do
              calc(i+1, k, num)
              k += 1
              break if k >= j+num.to_s.length
            end
            j = j + num.to_s.length
            next
          end
        end
        if j > 0
          if not($lins[i][j-1] =~ /\A\d\z/) and $lins[i][j-1] != '.'
            calc(i,j-1,num)
            j = j + num.to_s.length
            next
          end
        end
        if j + num.to_s.length <= $lins[i].length - 1
          if not($lins[i][j+num.to_s.length] =~ /\A\d\z/) and $lins[i][j+num.to_s.length] != '.'
            calc(i,j+num.to_s.length,num)
            j = j + num.to_s.length
            next
          end
        end
        puts num
        ans += num
        j += num.to_s.length
      end
      j = j + 1
      if j == $lins[i].length
        break
      end
    
    end
    i = i + 1
    if i == $lins.length
      break
    end

end
puts ans
puts tot
puts tot - ans
ans2 = 0

$nums.length.times {
  |i|
  $nums[0].length.times {
    |j|
    print $nums[i][j]
    print " "
    if $cnt[i][j] == 2
      ans2 += $nums[i][j]
    end
  }
  print "\n"
}
puts ans2
