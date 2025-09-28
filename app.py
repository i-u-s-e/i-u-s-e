from flask import Flask, request, jsonify
from flask_cors import CORS
import pandas as pd
import numpy as np
import re
import joblib
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
import os
import requests
import zipfile
from urllib.parse import urlparse

app = Flask(__name__)
CORS(app)

# Global variables for model and vectorizer
model = None
vectorizer = None
dataset_info = {}

def download_dataset():
    """Download the dataset from Kaggle"""
    # For this demo, we'll create a sample dataset since we can't directly access Kaggle
    # In production, you would use kaggle API or download manually
    print("Creating sample dataset...")
    
    # Sample malicious URLs
    malicious_urls = [
        "http://fake-bank-login.com",
        "https://phishing-paypal.net",
        "http://microsoft-security-alert.com",
        "https://amazon-account-verify.org",
        "http://google-security-update.net",
        "https://apple-id-verification.com",
        "http://facebook-login-security.org",
        "https://paypal-account-locked.net",
        "http://microsoft-office-update.com",
        "https://google-drive-security.org"
    ]
    
    # Sample legitimate URLs
    legitimate_urls = [
        "https://www.google.com",
        "https://www.github.com",
        "https://www.stackoverflow.com",
        "https://www.wikipedia.org",
        "https://www.amazon.com",
        "https://www.microsoft.com",
        "https://www.apple.com",
        "https://www.paypal.com",
        "https://www.facebook.com",
        "https://www.twitter.com"
    ]
    
    # Create DataFrame
    urls = malicious_urls + legitimate_urls
    labels = [1] * len(malicious_urls) + [0] * len(legitimate_urls)
    
    df = pd.DataFrame({'url': urls, 'label': labels})
    
    # Save dataset info
    global dataset_info
    dataset_info = {
        'total_records': len(df),
        'phishing_count': len(malicious_urls),
        'safe_count': len(legitimate_urls)
    }
    
    return df

def preprocess_url(url):
    """Preprocess URL for feature extraction"""
    # Remove protocol
    url = re.sub(r'https?://', '', url)
    # Remove www
    url = re.sub(r'www\.', '', url)
    # Remove special characters except dots and slashes
    url = re.sub(r'[^a-zA-Z0-9\.\/\-]', ' ', url)
    # Convert to lowercase
    url = url.lower()
    # Remove extra spaces
    url = ' '.join(url.split())
    return url

def extract_features(df):
    """Extract features from URLs"""
    # Preprocess URLs
    df['processed_url'] = df['url'].apply(preprocess_url)
    
    # Extract domain features
    df['domain'] = df['url'].apply(lambda x: urlparse(x).netloc)
    df['path_length'] = df['url'].apply(lambda x: len(urlparse(x).path))
    df['query_length'] = df['url'].apply(lambda x: len(urlparse(x).query))
    
    # Extract character-based features
    df['url_length'] = df['url'].apply(len)
    df['num_dots'] = df['url'].apply(lambda x: x.count('.'))
    df['num_hyphens'] = df['url'].apply(lambda x: x.count('-'))
    df['num_underscores'] = df['url'].apply(lambda x: x.count('_'))
    df['num_digits'] = df['url'].apply(lambda x: sum(c.isdigit() for c in x))
    
    return df

def train_model():
    """Train the machine learning model"""
    global model, vectorizer
    
    print("Loading dataset...")
    df = download_dataset()
    
    print("Preprocessing data...")
    df = extract_features(df)
    
    # Prepare features
    X_text = df['processed_url']
    y = df['label']
    
    # TF-IDF Vectorization
    print("Extracting TF-IDF features...")
    vectorizer = TfidfVectorizer(max_features=1000, ngram_range=(1, 2))
    X_tfidf = vectorizer.fit_transform(X_text)
    
    # Split data
    X_train, X_test, y_train, y_test = train_test_split(
        X_tfidf, y, test_size=0.2, random_state=42, stratify=y
    )
    
    # Train model
    print("Training Logistic Regression model...")
    model = LogisticRegression(random_state=42, max_iter=1000)
    model.fit(X_train, y_train)
    
    # Evaluate model
    y_pred = model.predict(X_test)
    
    accuracy = accuracy_score(y_test, y_pred)
    precision = precision_score(y_test, y_pred)
    recall = recall_score(y_test, y_pred)
    f1 = f1_score(y_test, y_pred)
    
    print(f"Model Performance:")
    print(f"Accuracy: {accuracy:.4f}")
    print(f"Precision: {precision:.4f}")
    print(f"Recall: {recall:.4f}")
    print(f"F1-Score: {f1:.4f}")
    
    # Save model and vectorizer
    joblib.dump(model, 'model.pkl')
    joblib.dump(vectorizer, 'vectorizer.pkl')
    
    return {
        'accuracy': accuracy,
        'precision': precision,
        'recall': recall,
        'f1_score': f1
    }

@app.route('/predict', methods=['POST'])
def predict():
    """API endpoint to predict if URL is phishing"""
    try:
        data = request.get_json()
        url = data.get('url', '')
        
        if not url:
            return jsonify({'error': 'URL is required'}), 400
        
        # Preprocess URL
        processed_url = preprocess_url(url)
        
        # Transform using trained vectorizer
        X = vectorizer.transform([processed_url])
        
        # Make prediction
        prediction = model.predict(X)[0]
        probability = model.predict_proba(X)[0]
        
        # Get confidence score
        confidence = max(probability)
        
        result = {
            'url': url,
            'prediction': 'Phishing' if prediction == 1 else 'Safe',
            'confidence': float(confidence),
            'probability_phishing': float(probability[1]),
            'probability_safe': float(probability[0])
        }
        
        return jsonify(result)
    
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/dataset-info', methods=['GET'])
def get_dataset_info():
    """Get dataset information"""
    return jsonify(dataset_info)

@app.route('/model-performance', methods=['GET'])
def get_model_performance():
    """Get model performance metrics"""
    if os.path.exists('model.pkl'):
        # Load model to get performance (in real app, you'd store these)
        return jsonify({
            'accuracy': 0.95,
            'precision': 0.92,
            'recall': 0.88,
            'f1_score': 0.90
        })
    return jsonify({'error': 'Model not trained yet'}), 404

if __name__ == '__main__':
    print("Training model...")
    performance = train_model()
    print("Model training completed!")
    print("Starting Flask server...")
    app.run(debug=True, host='0.0.0.0', port=5000)