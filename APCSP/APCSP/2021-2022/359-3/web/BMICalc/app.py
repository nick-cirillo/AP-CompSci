from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/process_data", methods=['GET', 'POST'])
def process_data():
    h_ft = request.form['h_ft'] #height in feet
    h_in = request.form['h_in'] #height in inches
    wt_lbs = request.form['wt_lbs']

    #TODO calculate BMI
    wt_kg = float(wt_lbs) / 2.205 #weight in kg
    h_in_tot = int(h_in) + (int(h_ft) * 12) #total height in inches
    h_m = float(h_in_tot) / 39.37 # height in meters
    bmi = wt_kg / h_m**2.0

    html = "<HTML><BODY>" + f"Your BMI is {round(bmi, 1)}.</BODY></HTML>"
    return(html)


@app.route("/")
def index():
    return render_template("index.html")