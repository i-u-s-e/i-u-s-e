#!/bin/bash

echo "Starting Flask backend server..."
echo "Installing Python dependencies..."
pip install -r requirements.txt

echo "Starting Flask server on http://localhost:5000"
python app.py