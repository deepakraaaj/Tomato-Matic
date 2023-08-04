# Tomato-Matic
"Tomato Matic : Ripe Tomatoes at Your Fingertips! 🍅🌿 Sense ethylene levels, predict harvest time, and enjoy perfectly ripe tomatoes every time! Our smart web app, powered by AI and IoT, takes the guesswork out of farming. Hosted on AWS for convenience. Embrace the future of farming with Tomato-Matic!"

# Ethylene Level-based Tomato Harvest Prediction Project

![Project Image](project_image.jpg)

## Table of Contents

1. [Introduction](#introduction)
2. [Project Overview](#project-overview)
3. [Hardware Requirements](#hardware-requirements)
4. [Software Requirements](#software-requirements)
5. [Installation and Setup](#installation-and-setup)
6. [Project Structure](#project-structure)
7. [Data Collection](#data-collection)
8. [Machine Learning Models](#machine-learning-models)
9. [Web Application](#web-application)
10. [NodeMCU Setup](#nodemcu-setup)
11. [Hosting on AWS](#hosting-on-aws)
12. [Conclusion](#conclusion)

## Introduction

This is a project that utilizes machine learning techniques and IoT to predict the optimal harvesting time for tomatoes based on the ethylene levels detected. Ethylene is a natural plant hormone associated with fruit ripening. By sensing the ethylene level, the project can predict the number of days left until the tomato is ready to be harvested.

## Project Overview

The project consists of four main components:

1. **Hardware Kit**: The hardware kit includes an ETO sensor attached to a NodeMCU ESP8266 board. The ETO sensor is responsible for measuring the ethylene level in the tomato and the NodeMCU board processes the data and sends it to the web application.

2. **Machine Learning Models**: Two machine learning models, Artificial Neural Network (ANN) and Random Forest Algorithm, have been developed. These models take the ethylene level data as input and predict the number of days remaining for the tomato to be harvested.

3. **Web Application**: A user-friendly web application has been created using the Kivy module in Python. The web app receives the ethylene level data from the NodeMCU and uses the trained models to make predictions. The web application is hosted on AWS for remote access.

4. **NodeMCU ESP8266 with C++**: The NodeMCU board is programmed using C++ to collect data from the ETO sensor and transmit it to the web application.

## Hardware Requirements

- NodeMCU ESP8266 Board
- ETO (Ethylene Oxide) Sensor
- Connecting Wires
- Power Supply (Battery or USB)

## Software Requirements

- Python 3.x
- Kivy module
- scikit-learn library
- Flask
- NodeMCU firmware
- Arduino IDE

## Installation and Setup

1. Clone the GitHub repository: [repository_link](https://github.com/your_username/project_repo.git)
2. Install Python and the required Python libraries.
3. Install the Arduino IDE and flash the NodeMCU board with the provided C++ code.
4. Set up an AWS account for hosting the web application.

## Project Structure

- `data_collection.py`: Python script to collect data from the ETO sensor and save it to a CSV file.
- `machine_learning_models.ipynb`: Jupyter Notebook containing the code to train ANN and Random Forest models.
- `web_app.py`: Python script for the web application using Kivy and Flask.
- `node_mcu_code.ino`: C++ code to program the NodeMCU board.
- `static/`: Folder containing static assets for the web application.
- `templates/`: Folder containing HTML templates for the web application.

## Data Collection

The `data_collection.py` script reads the ethylene level data from the ETO sensor attached to the NodeMCU board. The data is then saved to a CSV file for further processing and model training.

## Machine Learning Models

The `machine_learning_models.ipynb` notebook contains code to train two models: an Artificial Neural Network (ANN) and a Random Forest Algorithm. Both models use the ethylene level data from the CSV file to predict the number of days left for tomato harvesting.

## Web Application

The `web_app.py` script creates a user interface using the Kivy module and integrates the trained machine learning models using Flask. The web application receives data from the NodeMCU, processes it, and displays the prediction to the user.

## NodeMCU Setup

The `node_mcu_code.ino` C++ code is uploaded to the NodeMCU board using the Arduino IDE. This code enables the NodeMCU to read data from the ETO sensor and send it to the web application.

## Hosting on AWS

The web application is hosted on Amazon Web Services (AWS) to allow remote access and usage. The deployment process on AWS involves creating an EC2 instance, installing the required dependencies, and deploying the web application.

## Conclusion

This project successfully combines IoT, machine learning, and web development to predict the optimal harvesting time for tomatoes based on ethylene levels. By using the ETO sensor with NodeMCU, we can collect real-time data, which is then processed and used to make predictions through machine learning models. The user-friendly web application hosted on AWS allows remote access and provides an intuitive interface for users to interact with the system.

Please refer to the individual files in the repository for detailed implementation and code explanation. Feel free to contribute, report issues, and use this project for your own ethylene-based tomato harvesting prediction needs. Happy harvesting!
