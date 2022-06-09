import urllib.request
import codecs

url = "https://www.dailyscript.com/scripts/goodfellas.html"
openFile = urllib.request.urlopen(url)
file = openFile.read()
file = codecs.decode(file, encoding = 'utf-8', errors = 'ignore')
print(file)
score = 0
search = " the "
pos1 = 0
pos2 = 1
pos3 = 2
pos4 = 3
pos5 = 4
slider = [file[pos1], file[pos2], file[pos3], file[pos4], file[pos5]]

for i in range(len(file) - 5): # -4 for slider and -1 for 0-indexed range
    pos1 += 1
    pos2 += 1
    pos3 += 1
    pos4 += 1
    pos5 += 1
    slider = [file[pos1], file[pos2], file[pos3], file[pos4], file[pos5]]
    word = ''.join(slider)
    if word.lower() == search.lower():#" the ":
        score += 1

#TODO cancel above code and replace with shifting three-letter scanner

print(f"the word \"the\" appears {score} times")
