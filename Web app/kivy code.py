from flask import Flask, request, jsonify, render_template
import joblib

app = Flask(__name__)

# Load the pre-trained model
path= 'C:\\Users\\Deepakraj\\Desktop\\mini project\\test\\Web app\\model.pkl'

model = joblib.load(path)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/predict', methods=['POST'])
def predict():
    # Get the input from the user
    ethylene_level = request.form['ethylene_level']
    temperature = request.form['temperature']
    humidity = request.form['humidity']
    tomato_status = request.form['tomato_status']
    season = request.form['season']

    # Make a prediction using the pre-trained model
    prediction = model.predict([[ethylene_level, temperature, humidity, tomato_status, season]])

    # Render the index.html template with the predicted value
    return render_template('index.html', prediction=prediction)

if __name__ == '__main__':
    app.run(debug=True)
