import requests
import codecs

url = "https://www.dailyscript.com/scripts/goodfellas.html"

response = requests.get(url) #network response
#print(response.text)
file = response.text #script

def increment(list):
    return [x + 1 for x in list] #increments all items in list by 1

search = input("What word will you search Goodfellas for? ")
ogSearch = search #for final print
search = " " + search.lower() + " " #ensures word is not part of other word ("the" in "therefore")
searchLen = len(search) #no repeat computations
searchRange = range(searchLen) #same

posMatches = [search, " " + ogSearch + "!", " " + ogSearch + "?", " " + ogSearch + ".", " " + ogSearch + ",", " " + ogSearch + ";", " " + ogSearch + ")", "(" + ogSearch + " ", "(" + ogSearch + ")", " " + ogSearch + "\"", "\"" + ogSearch + " ", "\"" + ogSearch + "\"", " " + ogSearch + "'"]
#above accounts for punctuation

sliderIndex = [] #index of where the slider is in file
slider = [] #letters in slider

for i in searchRange:
    sliderIndex.append(i) #0, 1, 2, etc. based on search
    slider.append(file[sliderIndex[i]]) #first letters in script

score = 0 #score is number of matching words found

fileRange = range(len(file) - searchLen) # no repeat computations for for loops. - searchLen to account for the 0-indexed range and room the slider takes up.

for i in fileRange:

    for j in searchRange:
        slider[j] = (file[sliderIndex[j]])

    word = ''.join(slider) #joins slider list into one string

    if word.lower() in posMatches:#account for cases
        score += 1

    sliderIndex = increment(sliderIndex)

print(f"the word \"{ogSearch}\" appears {score} times")
