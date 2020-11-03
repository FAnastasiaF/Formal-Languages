# "+"

 * 0 + x = x // max = maxx
 * 4 + x = 4 // max = max4
 * 1 + 1 = 1 // max = max1
 * 1 + 2 = 5 // {max1.first, max2.second}
 * 1 + 3 = 3 // max = max3
 * 1 + 5 = 5 // max = max5
 * 1 + 6 = 6 // max = max6
 * 2 + 2 = 2 // max = {maximum(2.1.first, max2.2.first), maximum(2.1.first, max2.2.first)}
 * 2 + 3 = 6 // max = {max3.first, max2.first}
 * 2 + 5 = 5 // max = {max5.first, maximum(max2.second, max5.second)}
 * 2 + 6 = 6 // max = {max6.first, maximum(max2.second, max6.second))
 * 3 + 3 = 3 // max = {max3.1.first + max3.2.first, max3.1.second + max3.2.second)
 * 3 + 5 = 6 // max = {max3.first, max5.second}
 * 3 + 6 = 6 // max = {maximum(max6.first + max3.first), max6.second}
 * 5 + 5 = 5 // max = {max1, maximum(max5.1.second, max5.2.second)}
 * 5 + 6 = 6 // max = {max6.first, maximum(max6.second, max5.second)}
 * 6 + 6 = 6 // max = {maximum(max6.1.first + max6.2.first, maximum(max6.1.second, max6.2.second)}
 
 # "*"

 * 0* = 1 // max = max1
 * 1* = 1 // max = max1
 * 2* = 2 // max = max2
 * 3* = 4 // max = max4
 * 4* = 4 // max = max4
 * 5* = 5 // max = max5
 * 6* = 4 // max = max4
 
 # "."

 * 0.x = 0 // max = max0 
 * 1.x = x // max = maxx
 * x.1 = x // max = maxx
 * 2.x = 2 // max = max2
 * 4.x = 4 // max = max4
 * 3.0 = 2 // max = max3
 * 5.0 = 2 // max = {max5.second, max5,second}
 * 6.0 = 2 // max = {maximum(max6.second, max6,first), maximum(max6.second, max6,first)}
 * 3.2 = 2 // max = {max2.first + max3.first, max2.second + max3.second}
 * 3.3 = 3 // max = {max3.1.first + max3.2.first, max3.1.second + max3.2.second}
 * 3.4 = 4 // max = max4
 * 3.5 = 6 // max = {max3.first, max3.second + max5.second}
 * 3.6 = 6 // max = {max3.first + max6.first, max3.second + max6.second}
 * 5.2 = 2 // max = {maximum(max5.second + max2.first), maximum(max5.second + max2.first)}
 * 5.3 = 6 // max = {max3.first, max5.second}
 * 5.5 = 5 // max = {max1, maximum(max5.1.secomd + max5.2.second}
 * 5.6 = 6 // max = {max6.first, maximum(max5.second, max6.second)}
 * 6.2 = 2 // max = {maximum(max6.first + max2.first, max6.second), maximum(max6.first + max2.first, max6.second)}
 * 6.3 - 6 // max = {max3.first + max6.first, max6.second}
 * 6.5 = 6 // max = {max6.first, maximum(max6.second, max6.first + max5.second)}
 * 6.6 = 6 // max = {max6.1.first + max6.2.first, maximum(max6.1.second, max6.2.second + max 6.1.first)} 
 
