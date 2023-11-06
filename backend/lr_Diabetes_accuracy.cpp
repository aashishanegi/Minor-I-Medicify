#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>


struct Data {
    int Outcome;
    double Glucose;
    double BloodPressure;
    double SkinThickness;
    double Insulin;
    double BMI;
    double DiabetesPedigreeFunction;
};


double sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

// Predict the outcome based on the model
int predict(double weights[], Data data) {
    double z = weights[0]; 
    z += weights[1] * data.Glucose;
    z += weights[2] * data.BloodPressure;
    z += weights[3] * data.SkinThickness;
    z += weights[4] * data.Insulin;
    z += weights[5] * data.BMI;
    z += weights[6] * data.DiabetesPedigreeFunction;

    double probability = sigmoid(z);
    return (probability >= 0.5) ? 1 : 0;
}

// Update weights
void updateWeights(double weights[], Data data, double learningRate, int target) {
    double prediction = sigmoid(weights[0] +
                                weights[1] * data.Glucose +
                                weights[2] * data.BloodPressure +
                                weights[3] * data.SkinThickness +
                                weights[4] * data.Insulin +
                                weights[5] * data.BMI +
                                weights[6] * data.DiabetesPedigreeFunction);
    
    double error = target - prediction;

    weights[0] += learningRate * error;  
    weights[1] += learningRate * error * data.Glucose;
    weights[2] += learningRate * error * data.BloodPressure;
    weights[3] += learningRate * error * data.SkinThickness;
    weights[4] += learningRate * error * data.Insulin;
    weights[5] += learningRate * error * data.BMI;
    weights[6] += learningRate * error * data.DiabetesPedigreeFunction;
}

int main() {
    
    double weights[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double learningRate = 0.01;
    int epochs = 1000;

    // Read the dataset 
    std::vector<Data> dataset;
    std::ifstream file("diabetes.csv");
    std::string line;

    while (std::getline(file, line)) {
        Data data;
        std::stringstream ss(line);
        std::string value;
        getline(ss, value, ','); 

        try {
            getline(ss, value, ',');
            data.Glucose = std::stod(value);

            getline(ss, value, ',');
            data.BloodPressure = std::stod(value);

            getline(ss, value, ',');
            data.SkinThickness = std::stod(value);

            getline(ss, value, ',');
            data.Insulin = std::stod(value);

            getline(ss, value, ',');
            data.BMI = std::stod(value);

            getline(ss, value, ',');
            data.DiabetesPedigreeFunction = std::stod(value);

            getline(ss, value, ',');
            data.Outcome = std::stoi(value);

            dataset.push_back(data);
        } catch (const std::invalid_argument&) {
            
            std::cerr << "Skipping line due to invalid data: " << line << std::endl;
        }
    }
    
    // Train the model
    for (int epoch = 0; epoch < epochs; epoch++) {
        for (const Data& data : dataset) {
            int target = data.Outcome;
            updateWeights(weights, data, learningRate, target);
        }
    }

    // Make predictions
    for (const Data& data : dataset) {
        int prediction = predict(weights, data);
        std::cout << "Actual Outcome: " << data.Outcome << ", Predicted Outcome: " << prediction << std::endl;
    }
    
    // Calculate accuracy
    int correctPredictions = 0;
    int totalPredictions = dataset.size();

    for (const Data& data : dataset) {
        int prediction = predict(weights, data);
        if (prediction == data.Outcome) {
            correctPredictions++;
        }
    }

    double accuracy = static_cast<double>(correctPredictions) / totalPredictions;

    // Print accuracy
    std::cout << "Accuracy: " << (accuracy * 100) << "%" << std::endl;

    return 0;
}
