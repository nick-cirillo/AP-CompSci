import requests
import sys

url = "https://www.dailyscript.com/scripts/goodfellas.html"\

response = requests.get(url)
script = response.text

score = 0
searchTerm = sys.argv[1]
words = script.split()
#print(words)

for word in words:
    if word.lower() == searchTerm.lower():
        score += 1


print(f"the word \"{searchTerm}\" appears {score} times")