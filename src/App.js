import React, { useState, useEffect } from 'react';
import axios from 'axios';

function App() {
  const [url, setUrl] = useState('');
  const [result, setResult] = useState(null);
  const [loading, setLoading] = useState(false);
  const [datasetInfo, setDatasetInfo] = useState(null);
  const [modelPerformance, setModelPerformance] = useState(null);

  useEffect(() => {
    // Fetch dataset info and model performance on component mount
    fetchDatasetInfo();
    fetchModelPerformance();
  }, []);

  const fetchDatasetInfo = async () => {
    try {
      const response = await axios.get('http://localhost:5000/dataset-info');
      setDatasetInfo(response.data);
    } catch (error) {
      console.error('Error fetching dataset info:', error);
    }
  };

  const fetchModelPerformance = async () => {
    try {
      const response = await axios.get('http://localhost:5000/model-performance');
      setModelPerformance(response.data);
    } catch (error) {
      console.error('Error fetching model performance:', error);
    }
  };

  const checkUrl = async () => {
    if (!url.trim()) {
      alert('Please enter a URL to check');
      return;
    }

    setLoading(true);
    setResult(null);

    try {
      const response = await axios.post('http://localhost:5000/predict', {
        url: url
      });
      setResult(response.data);
    } catch (error) {
      console.error('Error checking URL:', error);
      setResult({
        error: 'Failed to check URL. Please try again.'
      });
    } finally {
      setLoading(false);
    }
  };

  const getResultColor = (prediction) => {
    if (prediction === 'Phishing') {
      return 'text-red-600 bg-red-50 border-red-200';
    } else if (prediction === 'Safe') {
      return 'text-green-600 bg-green-50 border-green-200';
    }
    return 'text-gray-600 bg-gray-50 border-gray-200';
  };

  const getConfidenceColor = (confidence) => {
    if (confidence >= 0.8) {
      return 'text-red-600';
    } else if (confidence >= 0.6) {
      return 'text-yellow-600';
    } else {
      return 'text-green-600';
    }
  };

  return (
    <div className="min-h-screen bg-gradient-to-br from-blue-50 to-indigo-100">
      <div className="container mx-auto px-4 py-8">
        {/* Header */}
        <div className="text-center mb-8">
          <h1 className="text-4xl font-bold text-gray-800 mb-2">
            🛡️ Phishing URL Detector
          </h1>
          <p className="text-gray-600 text-lg">
            Protect yourself from malicious websites with AI-powered detection
          </p>
        </div>

        <div className="grid grid-cols-1 lg:grid-cols-3 gap-8">
          {/* Main Detection Card */}
          <div className="lg:col-span-2">
            <div className="bg-white rounded-xl shadow-lg p-6">
              <h2 className="text-2xl font-semibold text-gray-800 mb-6">
                Check URL Safety
              </h2>
              
              <div className="space-y-4">
                <div>
                  <label className="block text-sm font-medium text-gray-700 mb-2">
                    Enter URL to check:
                  </label>
                  <input
                    type="url"
                    value={url}
                    onChange={(e) => setUrl(e.target.value)}
                    placeholder="https://example.com"
                    className="w-full px-4 py-3 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                  />
                </div>
                
                <button
                  onClick={checkUrl}
                  disabled={loading}
                  className="w-full bg-blue-600 hover:bg-blue-700 disabled:bg-blue-400 text-white font-semibold py-3 px-6 rounded-lg transition duration-200 flex items-center justify-center"
                >
                  {loading ? (
                    <>
                      <svg className="animate-spin -ml-1 mr-3 h-5 w-5 text-white" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
                        <circle className="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" strokeWidth="4"></circle>
                        <path className="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4zm2 5.291A7.962 7.962 0 014 12H0c0 3.042 1.135 5.824 3 7.938l3-2.647z"></path>
                      </svg>
                      Scanning...
                    </>
                  ) : (
                    '🔍 Check URL'
                  )}
                </button>
              </div>

              {/* Results */}
              {result && (
                <div className="mt-6">
                  {result.error ? (
                    <div className="bg-red-50 border border-red-200 rounded-lg p-4">
                      <p className="text-red-600">{result.error}</p>
                    </div>
                  ) : (
                    <div className={`border-2 rounded-lg p-6 ${getResultColor(result.prediction)}`}>
                      <div className="text-center">
                        <h3 className="text-2xl font-bold mb-2">
                          {result.prediction === 'Phishing' ? '⚠️ Phishing Detected!' : '✅ Safe URL'}
                        </h3>
                        <p className="text-lg mb-4">
                          <strong>Result:</strong> {result.prediction}
                        </p>
                        <div className="space-y-2">
                          <p>
                            <span className="font-semibold">Confidence:</span>{' '}
                            <span className={`font-bold ${getConfidenceColor(result.confidence)}`}>
                              {(result.confidence * 100).toFixed(1)}%
                            </span>
                          </p>
                          <div className="grid grid-cols-2 gap-4 text-sm">
                            <div>
                              <span className="font-semibold">Phishing Probability:</span>{' '}
                              <span className="text-red-600">
                                {(result.probability_phishing * 100).toFixed(1)}%
                              </span>
                            </div>
                            <div>
                              <span className="font-semibold">Safe Probability:</span>{' '}
                              <span className="text-green-600">
                                {(result.probability_safe * 100).toFixed(1)}%
                              </span>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                  )}
                </div>
              )}
            </div>
          </div>

          {/* Sidebar with Info */}
          <div className="space-y-6">
            {/* Dataset Info Card */}
            {datasetInfo && (
              <div className="bg-white rounded-xl shadow-lg p-6">
                <h3 className="text-xl font-semibold text-gray-800 mb-4">
                  📊 Dataset Information
                </h3>
                <div className="space-y-3">
                  <div className="flex justify-between">
                    <span className="text-gray-600">Total Records:</span>
                    <span className="font-semibold">{datasetInfo.total_records}</span>
                  </div>
                  <div className="flex justify-between">
                    <span className="text-red-600">Phishing URLs:</span>
                    <span className="font-semibold text-red-600">{datasetInfo.phishing_count}</span>
                  </div>
                  <div className="flex justify-between">
                    <span className="text-green-600">Safe URLs:</span>
                    <span className="font-semibold text-green-600">{datasetInfo.safe_count}</span>
                  </div>
                </div>
              </div>
            )}

            {/* Model Performance Card */}
            {modelPerformance && (
              <div className="bg-white rounded-xl shadow-lg p-6">
                <h3 className="text-xl font-semibold text-gray-800 mb-4">
                  🎯 Model Performance
                </h3>
                <div className="space-y-3">
                  <div className="flex justify-between">
                    <span className="text-gray-600">Accuracy:</span>
                    <span className="font-semibold text-blue-600">
                      {(modelPerformance.accuracy * 100).toFixed(1)}%
                    </span>
                  </div>
                  <div className="flex justify-between">
                    <span className="text-gray-600">Precision:</span>
                    <span className="font-semibold text-green-600">
                      {(modelPerformance.precision * 100).toFixed(1)}%
                    </span>
                  </div>
                  <div className="flex justify-between">
                    <span className="text-gray-600">Recall:</span>
                    <span className="font-semibold text-purple-600">
                      {(modelPerformance.recall * 100).toFixed(1)}%
                    </span>
                  </div>
                  <div className="flex justify-between">
                    <span className="text-gray-600">F1-Score:</span>
                    <span className="font-semibold text-orange-600">
                      {(modelPerformance.f1_score * 100).toFixed(1)}%
                    </span>
                  </div>
                </div>
              </div>
            )}

            {/* How it Works Card */}
            <div className="bg-white rounded-xl shadow-lg p-6">
              <h3 className="text-xl font-semibold text-gray-800 mb-4">
                🔬 How It Works
              </h3>
              <div className="space-y-3 text-sm text-gray-600">
                <p>• Analyzes URL structure and patterns</p>
                <p>• Uses TF-IDF feature extraction</p>
                <p>• Trained on malicious URL dataset</p>
                <p>• Logistic Regression algorithm</p>
                <p>• Provides confidence scores</p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}

export default App;