#
# grader.py will inspect HTML files for certain tags and tally grade
#
#
# Navigate folders to find html files
# Process each HTML file
# Print score for each HTMLM file
#

import os

def gradePage(filePath, name):
    img = 0
    table = 0
    a = 0
    css = 0
    btsp = 0 #bootstrap
    score = 0 #out of 5

    file = open(filePath)
    for line in file:
        if "<img" in line.lower():
            img = 1
        if "<table" in line.lower():
            table = 1
        if "<a" in line.lower():
            a = 1
        if ".css" in line.lower():
            css = 1
        if "bootstrap" in line.lower():
            btsp = 1
        score = img + table + a + css + btsp
    print(f"{name} got a score of {score}")
    print(f"img={img}, table={table}, link={a}, css={css}, bootstrap={btsp}\n")

filepath = "/workspaces/90916516/2021-2022/359-3/web/grader/homepage3/"

dirs = os.listdir('./homepage3')


for dir in dirs:
    subfolder = filepath + dir
    username = dir
    files = os.listdir(subfolder)
    for file in files:
        fullFilePath = subfolder + "/" + file
        if "index.html" in file:
            gradePage(fullFilePath, dir)

