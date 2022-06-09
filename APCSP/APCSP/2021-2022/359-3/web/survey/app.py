from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/process_data", methods=['GET', 'POST'])
def process_data():
    lfc = request.form['lfc']
    flavor = request.form['flavor']
    mis = request.form['state']
    sport = request.form['sport']
    favgame = request.form['videogame']

    f = open("results.txt", "a")
    record = lfc.lower() + '|' + flavor + '|' + mis.lower() + '|' + sport.lower() + '|' + favgame + '\n'
    f.write(record)
    f.close

    html = '<HTML><BODY>'
    html = html + "Thank you! Your response has been recorded."
    html = html + '<br>Click <a href="/results">here</a> to see all results'
    html = html + "</BODY></HTML>"
    return(html)


@app.route("/")
def index():
    return render_template("index.html")

@app.route("/results")
def results():
    f = open("results.txt", "r")

    html = "<html><body>"
    html += "<table border=1>"
    html += "<tr>"
    html += "<th>Least Favorite Classes</th>"
    html += "<th>Favorite Ice Cream Flavor</th>"
    html += "<th>Preferred Vacation Destination</th>"
    html += "<th>Sport Played</th>"
    html += "<th>Favorite Videogame</th>"
    html += "</tr>"

    for line in f:
        cols = line.split('|')
        html += '<tr>'
        html += '<td>' + cols[0] + '</td>'
        html += '<td>' + cols[1] + '</td>'
        html += '<td>' + cols[2] + '</td>'
        html += '<td>' + cols[3] + '</td>'
        html += '<td>' + cols[4] + '</td>'
        html +='<tr>'

    html += '</table></body></html>'
    f.close()
    return(html)
