#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


struct PatientDetails {
    std::string Pid;
    std::string Name;
    int Age;
    std::string Gender;
};

struct BloodData {
    std::string Pid;
    double RedBloodCellCount;
    double PackedCellVolume;
    double MeanCellVolume;
    double MeanCellHemoglobin;
    double RedCellDistributionWidth;
    double WhiteBloodCellCount;
    double Platelet;
    double Hemoglobin;
};


struct DiabetesData {
    std::string Pid;
    int Glucose;
    int BloodPressure;
    int SkinThickness;
    int Insulin;
    double BMI;
    double DiabetesPedigreeFunction;
    int Outcome;
};


struct LiverData {
    std::string Pid;
    double TotalBilirubin;
    double DirectBilirubin;
    int AlkalinePhosphotase;
    int AlamineAminotransferase;
    int AspartateAminotransferase;
    double TotalProtiens;
    double Albumin;
    double AlbuminAndGlobulinRatio;
    int Dataset;
};


void search(const std::string& searchPid,const std::vector<PatientDetails>& patientDetails, const std::vector<BloodData>& patientData, const std::vector<DiabetesData>& diabetesData, const std::vector<LiverData>& liverData) {
    bool found = false;
    
    for (const PatientDetails& details : patientDetails) {
        if (details.Pid == searchPid) {
            found = true;
            std::cout << "Patient Details for PID " << searchPid << ":\n";
            std::cout << "Name: " << details.Name << std::endl;
            std::cout << "Age: " << details.Age << std::endl;
            std::cout << "Gender: " << details.Gender << std::endl;
            std::cout << "\n";
        }
    }
    
    
    for (const BloodData& patient : patientData) {
        if (patient.Pid == searchPid) {
            found = true;
            std::cout << "Blood Test Results for PID " << searchPid << ":\n";
            std::cout << "Red Blood Cell Count: " << patient.RedBloodCellCount << std::endl;
            std::cout << "Packed Cell Volume: " << patient.PackedCellVolume << std::endl;
            std::cout << "Mean Cell Volume: " << patient.MeanCellVolume << std::endl;
            std::cout << "Mean Cell Hemoglobin: " << patient.MeanCellHemoglobin << std::endl;
            std::cout << "Red Cell Distribution Width: " << patient.RedCellDistributionWidth << std::endl;
            std::cout << "White Blood Cell Count: " << patient.WhiteBloodCellCount << std::endl;
            std::cout << "Platelet: " << patient.Platelet << std::endl;
            std::cout << "Hemoglobin: " << patient.Hemoglobin << std::endl;
            std::cout << "\n";
        }
    }

    for (const DiabetesData& diabetes : diabetesData) {
        if (diabetes.Pid == searchPid) {
            found = true;
            std::cout << "Diabetes Test Results for PID " << searchPid << ":\n";
            std::cout << "Glucose: " << diabetes.Glucose << std::endl;
            std::cout << "Blood Pressure: " << diabetes.BloodPressure << std::endl;
            std::cout << "Skin Thickness: " << diabetes.SkinThickness << std::endl;
            std::cout << "Insulin: " << diabetes.Insulin << std::endl;
            std::cout << "BMI: " << diabetes.BMI << std::endl;
            std::cout << "Diabetes Pedigree Function: " << diabetes.DiabetesPedigreeFunction << std::endl;
            std::cout << "Outcome: " << diabetes.Outcome << std::endl;
            std::cout << "\n";
        }
    }

    for (const LiverData& liver : liverData) {
        if (liver.Pid == searchPid) {
            found = true;
            std::cout << "Liver Test Results for PID " << searchPid << ":\n";
            std::cout << "Total Bilirubin: " << liver.TotalBilirubin << std::endl;
            std::cout << "Direct Bilirubin: " << liver.DirectBilirubin << std::endl;
            std::cout << "Alkaline Phosphotase: " << liver.AlkalinePhosphotase << std::endl;
            std::cout << "Alamine Aminotransferase: " << liver.AlamineAminotransferase << std::endl;
            std::cout << "Aspartate Aminotransferase: " << liver.AspartateAminotransferase << std::endl;
            std::cout << "Total Protiens: " << liver.TotalProtiens << std::endl;
            std::cout << "Albumin: " << liver.Albumin << std::endl;
            std::cout << "Albumin and Globulin Ratio: " << liver.AlbuminAndGlobulinRatio << std::endl;
            std::cout << "Dataset: " << liver.Dataset << std::endl;
            std::cout << "\n";
        }
    }

    if (!found) {
        std::cout << "Patient with PID " << searchPid << " not found." << std::endl;
    }
}

void addPatientDetails(std::vector<PatientDetails>& patientDetails) {
    PatientDetails newPatient;
    std::cout << "Enter PID: ";
    std::cin >> newPatient.Pid;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, newPatient.Name);
    std::cout << "Enter Age: ";
    std::cin >> newPatient.Age;
    std::cout << "Enter Gender (Male/Female): ";
    std::cin >> newPatient.Gender;

    
    patientDetails.push_back(newPatient);

    
    std::ofstream patientDetailsFile("patientdetails.csv", std::ios::app); // Open the file in append mode
    if (patientDetailsFile.is_open()) {
        patientDetailsFile << newPatient.Pid << ',' << newPatient.Name << ',' << newPatient.Age << ',' << newPatient.Gender << '\n';
        patientDetailsFile.close();
    } else {
        std::cerr << "Failed to open patient details file for writing." << std::endl;
    }
}

void addBloodData(std::vector<BloodData>& patientData) {
    BloodData newPatient;
    std::cout << "Enter PID: ";
    std::cin >> newPatient.Pid;
    std::cout << "Enter Red Blood Cell Count: ";
    std::cin >> newPatient.RedBloodCellCount;
    std::cout << "Enter Packed Cell Volume: ";
    std::cin >> newPatient.PackedCellVolume;
    std::cout << "Enter Mean Cell Volume: ";
    std::cin >> newPatient.MeanCellVolume;
    std::cout << "Enter Mean Cell Hemoglobin: ";
    std::cin >> newPatient.MeanCellHemoglobin;
    std::cout << "Enter Red Cell Distribution Width: ";
    std::cin >> newPatient.RedCellDistributionWidth;
    std::cout << "Enter White Blood Cell Count: ";
    std::cin >> newPatient.WhiteBloodCellCount;
    std::cout << "Enter Platelet: ";
    std::cin >> newPatient.Platelet;
    std::cout << "Enter Hemoglobin: ";
    std::cin >> newPatient.Hemoglobin;

    
    patientData.push_back(newPatient);


    std::ofstream patientDataFile("blood.csv", std::ios::app); 
    if (patientDataFile.is_open()) {
        patientDataFile << newPatient.Pid << ',' << newPatient.RedBloodCellCount << ',' << newPatient.PackedCellVolume << ','
                        << newPatient.MeanCellVolume << ',' << newPatient.MeanCellHemoglobin << ','
                        << newPatient.RedCellDistributionWidth << ',' << newPatient.WhiteBloodCellCount << ','
                        << newPatient.Platelet << ',' << newPatient.Hemoglobin << '\n';
        patientDataFile.close();
    } else {
        std::cerr << "Failed to open patient data file for writing." << std::endl;
    }
}


void addDiabetesData(std::vector<DiabetesData>& diabetesData) {
    DiabetesData newDiabetesData;
    std::cout << "Enter PID: ";
    std::cin >> newDiabetesData.Pid;
    std::cout << "Enter Glucose: ";
    std::cin >> newDiabetesData.Glucose;
    std::cout << "Enter Blood Pressure: ";
    std::cin >> newDiabetesData.BloodPressure;
    std::cout << "Enter Skin Thickness: ";
    std::cin >> newDiabetesData.SkinThickness;
    std::cout << "Enter Insulin: ";
    std::cin >> newDiabetesData.Insulin;
    std::cout << "Enter BMI: ";
    std::cin >> newDiabetesData.BMI;
    std::cout << "Enter Diabetes Pedigree Function: ";
    std::cin >> newDiabetesData.DiabetesPedigreeFunction;
    std::cout << "Enter Outcome: ";
    std::cin >> newDiabetesData.Outcome;

    
    diabetesData.push_back(newDiabetesData);

   
    std::ofstream diabetesDataFile("diabetes.csv", std::ios::app); 
    if (diabetesDataFile.is_open()) {
        diabetesDataFile << newDiabetesData.Pid << ',' << newDiabetesData.Glucose << ',' << newDiabetesData.BloodPressure << ','
                         << newDiabetesData.SkinThickness << ',' << newDiabetesData.Insulin << ','
                         << newDiabetesData.BMI << ',' << newDiabetesData.DiabetesPedigreeFunction << ',' << newDiabetesData.Outcome << '\n';
        diabetesDataFile.close();
    } else {
        std::cerr << "Failed to open diabetes data file for writing." << std::endl;
    }
}

void addLiverData(std::vector<LiverData>& liverData) {
    LiverData newLiverData;
    std::cout << "Enter PID: ";
    std::cin >> newLiverData.Pid;
    std::cout << "Enter Total Bilirubin: ";
    std::cin >> newLiverData.TotalBilirubin;
    std::cout << "Enter Direct Bilirubin: ";
    std::cin >> newLiverData.DirectBilirubin;
    std::cout << "Enter Alkaline Phosphotase: ";
    std::cin >> newLiverData.AlkalinePhosphotase;
    std::cout << "Enter Alamine Aminotransferase: ";
    std::cin >> newLiverData.AlamineAminotransferase;
    std::cout << "Enter Aspartate Aminotransferase: ";
    std::cin >> newLiverData.AspartateAminotransferase;
    std::cout << "Enter Total Protiens: ";
    std::cin >> newLiverData.TotalProtiens;
    std::cout << "Enter Albumin: ";
    std::cin >> newLiverData.Albumin;
    std::cout << "Enter Albumin and Globulin Ratio: ";
    std::cin >> newLiverData.AlbuminAndGlobulinRatio;
    std::cout << "Enter Dataset: ";
    std::cin >> newLiverData.Dataset;

   
    liverData.push_back(newLiverData);

   
    std::ofstream liverDataFile("liver.csv", std::ios::app); 
    if (liverDataFile.is_open()) {
        liverDataFile << newLiverData.Pid << ','<< newLiverData.TotalBilirubin << ',' << newLiverData.DirectBilirubin << ','
                      << newLiverData.AlkalinePhosphotase << ',' << newLiverData.AlamineAminotransferase << ','
                      << newLiverData.AspartateAminotransferase << ',' << newLiverData.TotalProtiens << ','
                      << newLiverData.Albumin << ',' << newLiverData.AlbuminAndGlobulinRatio << ','
                      << newLiverData.Dataset << '\n';
        liverDataFile.close();
    } else {
        std::cerr << "Failed to open liver data file for writing." << std::endl;
    }
}



int main() {
    
    std::vector<PatientDetails> patientDetails;
    std::ifstream patientDetailsFile("patientdetails.csv");
    if (!patientDetailsFile.is_open()) {
        std::cerr << "Failed to open patient details file." << std::endl;
        return 1;
    }

    std::string line;
    
    std::getline(patientDetailsFile, line);

    while (std::getline(patientDetailsFile, line)) {
        std::istringstream iss(line);
        PatientDetails details;
        std::string value;

        std::getline(iss, details.Pid, ',');
        std::getline(iss, details.Name, ',');
        iss >> details.Age;
        std::getline(iss, value, ','); 
        std::getline(iss, details.Gender, ',');

        patientDetails.push_back(details);
    }
    patientDetailsFile.close();
    
    
    
    std::vector<BloodData> patientData;
    std::ifstream bloodTestDataFile("blood.csv");
    if (!bloodTestDataFile.is_open()) {
        std::cerr << "Failed to open blood test data file." << std::endl;
        return 1;
    }

    
    std::getline(bloodTestDataFile, line);

    while (std::getline(bloodTestDataFile, line)) {
        std::istringstream iss(line);
        BloodData patient;
        std::string value;

        std::getline(iss, patient.Pid, ',');
        iss >> patient.RedBloodCellCount;
        std::getline(iss, value, ',');
        iss >> patient.PackedCellVolume;
        std::getline(iss, value, ',');
        iss >> patient.MeanCellVolume;
        std::getline(iss, value, ',');
        iss >> patient.MeanCellHemoglobin;
        std::getline(iss, value, ',');
        iss >> patient.RedCellDistributionWidth;
        std::getline(iss, value, ',');
        iss >> patient.WhiteBloodCellCount;
        std::getline(iss, value, ',');
        iss >> patient.Platelet;
        std::getline(iss, value, ',');
        iss >> patient.Hemoglobin;

        patientData.push_back(patient);
    }
    bloodTestDataFile.close();

    
    std::vector<DiabetesData> diabetesData;
    std::ifstream diabetesTestDataFile("diabetes.csv");
    if (!diabetesTestDataFile.is_open()) {
        std::cerr << "Failed to open diabetes test data file." << std::endl;
        return 1;
    }

    
    std::getline(diabetesTestDataFile, line);

    while (std::getline(diabetesTestDataFile, line)) {
        std::istringstream iss(line);
        DiabetesData diabetes;
        std::string value;

        std::getline(iss, diabetes.Pid, ',');
        iss >> diabetes.Glucose;
        std::getline(iss, value, ',');
        iss >> diabetes.BloodPressure;
        std::getline(iss, value, ',');
        iss >> diabetes.SkinThickness;
        std::getline(iss, value, ',');
        iss >> diabetes.Insulin;
        std::getline(iss, value, ',');
        iss >> diabetes.BMI;
        std::getline(iss, value, ',');
        iss >> diabetes.DiabetesPedigreeFunction;
        std::getline(iss, value, ',');
        iss >> diabetes.Outcome;

        diabetesData.push_back(diabetes);
    }
    diabetesTestDataFile.close();

    
    std::vector<LiverData> liverData;
    std::ifstream liverTestDataFile("liver.csv");
    if (!liverTestDataFile.is_open()) {
        std::cerr << "Failed to open liver test data file." << std::endl;
        return 1;
    }

    
    std::getline(liverTestDataFile, line);

    while (std::getline(liverTestDataFile, line)) {
        std::istringstream iss(line);
        LiverData liver;
        std::string value;

        std::getline(iss, liver.Pid, ',');
        iss >> liver.TotalBilirubin;
        std::getline(iss, value, ',');
        iss >> liver.DirectBilirubin;
        std::getline(iss, value, ',');
        iss >> liver.AlkalinePhosphotase;
        std::getline(iss, value, ',');
        iss >> liver.AlamineAminotransferase;
        std::getline(iss, value, ',');
        iss >> liver.AspartateAminotransferase;
        std::getline(iss, value, ',');
        iss >> liver.TotalProtiens;
        std::getline(iss, value, ',');
        iss >> liver.Albumin;
        std::getline(iss, value, ',');
        iss >> liver.AlbuminAndGlobulinRatio;
        std::getline(iss, value, ',');
        iss >> liver.Dataset;

        liverData.push_back(liver);
    }
    liverTestDataFile.close();

    
int choice;
    do {
        std::cout << "Select an option:\n";
        std::cout << "1. Add Patient Details\n";
        std::cout << "2. Add Blood Test Report\n";
        std::cout << "3. Add Diabetes Test Report\n";
        std::cout << "4. Add Liver Test Report\n";
        std::cout << "5. Search Patient reports\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addPatientDetails(patientDetails);
                break;
            case 2:
               addBloodData(patientData);
                break;
            case 3:
               addDiabetesData(diabetesData);
                break;
            case 4:
                addLiverData(liverData);
            case 5:
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    std::string searchPid;
    std::cout << "Enter PID for the searching: \n";
    std::cin >> searchPid;
    
    search(searchPid, patientDetails, patientData, diabetesData, liverData);

    return 0;
}
