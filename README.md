# Phishing URL Detection Web App

A machine learning-powered web application that detects phishing URLs using a trained Logistic Regression model.

## Features

- 🔍 **URL Analysis**: Enter any URL to check if it's safe or malicious
- 🤖 **AI-Powered**: Uses machine learning with TF-IDF feature extraction
- 📊 **Performance Metrics**: Shows model accuracy, precision, recall, and F1-score
- 📈 **Dataset Info**: Displays information about the training dataset
- 🎨 **Modern UI**: Clean, responsive design with TailwindCSS
- ⚡ **Real-time**: Fast predictions with confidence scores

## Tech Stack

### Backend
- **Python Flask**: Web framework
- **scikit-learn**: Machine learning library
- **TF-IDF Vectorizer**: Feature extraction
- **Logistic Regression**: Classification algorithm
- **joblib**: Model serialization

### Frontend
- **React**: Frontend framework
- **TailwindCSS**: Styling
- **Axios**: HTTP client
- **Responsive Design**: Mobile-friendly

## Installation & Setup

### Prerequisites
- Python 3.8+
- Node.js 16+
- npm or yarn

### Backend Setup

1. Install Python dependencies:
```bash
pip install -r requirements.txt
```

2. Run the Flask server:
```bash
python app.py
```

The backend will:
- Download and preprocess the dataset
- Train the machine learning model
- Start the Flask server on `http://localhost:5000`

### Frontend Setup

1. Install Node.js dependencies:
```bash
npm install
```

2. Start the React development server:
```bash
npm start
```

The frontend will be available at `http://localhost:3000`

## API Endpoints

### POST /predict
Check if a URL is phishing or safe.

**Request:**
```json
{
  "url": "https://example.com"
}
```

**Response:**
```json
{
  "url": "https://example.com",
  "prediction": "Safe",
  "confidence": 0.95,
  "probability_phishing": 0.05,
  "probability_safe": 0.95
}
```

### GET /dataset-info
Get information about the training dataset.

**Response:**
```json
{
  "total_records": 20,
  "phishing_count": 10,
  "safe_count": 10
}
```

### GET /model-performance
Get model performance metrics.

**Response:**
```json
{
  "accuracy": 0.95,
  "precision": 0.92,
  "recall": 0.88,
  "f1_score": 0.90
}
```

## How It Works

1. **Data Preprocessing**: URLs are cleaned and normalized
2. **Feature Extraction**: TF-IDF vectorization captures URL patterns
3. **Model Training**: Logistic Regression learns from labeled data
4. **Prediction**: New URLs are classified with confidence scores
5. **Real-time Detection**: Web interface provides instant results

## Model Performance

The model achieves high accuracy by analyzing:
- URL structure and length
- Domain characteristics
- Special character patterns
- N-gram features from TF-IDF

## Usage

1. Open the web application
2. Enter a URL in the input field
3. Click "Check URL" to analyze
4. View the result with confidence score
5. Check model performance metrics

## Development

### Project Structure
```
/
├── app.py                 # Flask backend
├── requirements.txt       # Python dependencies
├── package.json          # Node.js dependencies
├── src/
│   ├── App.js            # Main React component
│   ├── index.js          # React entry point
│   └── index.css         # TailwindCSS styles
└── public/
    └── index.html          # HTML template
```

### Adding New Features

1. **Backend**: Modify `app.py` to add new endpoints
2. **Frontend**: Update `src/App.js` for UI changes
3. **Styling**: Use TailwindCSS classes for design

## Security Note

This is a demonstration application. For production use:
- Implement proper authentication
- Add rate limiting
- Use HTTPS
- Validate and sanitize inputs
- Consider using a more comprehensive dataset

## License

MIT License - feel free to use and modify for your projects.