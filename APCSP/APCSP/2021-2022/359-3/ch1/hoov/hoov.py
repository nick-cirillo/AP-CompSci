# read hoovies data and total it

# read each line
# extract price
# update running total
# output total

import re

f_hoov = open('hoov.txt', 'r')
totalPrice = 0
numCars = 0

for line in f_hoov:
    x = re.search("^.*\$(.*)$", line)
    if x is not None:
        numCars += 1
        price = x.group(1)
        price = price.replace(',','')
        totalPrice += int(price)
avgPrice = totalPrice/numCars

print("Hoovie owns %d cars.\nAverage Car Price: $%d\nTotal Price of Hoovie's Garage: $%d" % (numCars, round(avgPrice,2), totalPrice))

