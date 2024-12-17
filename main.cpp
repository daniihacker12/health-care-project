#include <iostream>
#include <string>
using namespace std;

// Base Class
class HealthSystem {
public:
    bool isPoweredOn;
    string userName;

    HealthSystem() : isPoweredOn(false), userName("User") {}

    void powerOn() {
        isPoweredOn = true;
        cout << "Health System Powered On. Welcome, " << userName << "!" << endl;
    }

    void powerOff() {
        isPoweredOn = false;
        cout << "Health System Powered Off. Goodbye, " << userName << "!" << endl;
    }

    void displayStatus() {
        if (isPoweredOn)
            cout << "Health System is On" << endl;
        else
            cout << "Health System is Off" << endl;
    }

    void setUserName(const string& name) {
        userName = name;
    }
};

// Derived Class: VitalSignMonitor
class VitalSignMonitor : public HealthSystem {
private:
    const int maxLogSize = 5;
    int heartRateLog[5] = {0};
    int bpLog[5][2] = {{0}};
    int glucoseLog[5] = {0};
    double tempLog[5] = {0.0};
    int logIndex = 0;

public:
    void readHeartRate() {
        if (isPoweredOn) {
            int heartRate = 72 + (rand() % 10); // Random heart rate
            heartRateLog[logIndex] = heartRate;
            cout << "Heart Rate: " << heartRate << " bpm" << endl;
        } else {
            cout << "System is Off. Please power on the system first." << endl;
        }
    }

    void readBloodPressure() {
        if (isPoweredOn) {
            int systolic = 120 + (rand() % 5);
            int diastolic = 80 + (rand() % 5);
            bpLog[logIndex][0] = systolic;
            bpLog[logIndex][1] = diastolic;
            cout << "Blood Pressure: " << systolic << "/" << diastolic << " mmHg" << endl;
        } else {
            cout << "System is Off. Please power on the system first." << endl;
        }
    }

    void readGlucoseLevel() {
        if (isPoweredOn) {
            int glucose = 98 + (rand() % 10);
            glucoseLog[logIndex] = glucose;
            cout << "Glucose Level: " << glucose << " mg/dL" << endl;
        } else {
            cout << "System is Off. Please power on the system first." << endl;
        }
    }

    void readTemperature() {
        if (isPoweredOn) {
            double temp = 98.0 + (rand() % 5) * 0.1;
            tempLog[logIndex] = temp;
            cout << "Body Temperature: " << temp << "°F" << endl;
        } else {
            cout << "System is Off. Please power on the system first." << endl;
        }
    }

    void logVitals() {
        if (isPoweredOn) {
            readHeartRate();
            readBloodPressure();
            readGlucoseLevel();
            readTemperature();
            logIndex = (logIndex + 1) % maxLogSize;
        } else {
            cout << "System is Off. Please power on the system first." << endl;
        }
    }

    void displayLog() {
        if (isPoweredOn) {
            cout << "\n---- Vital Signs Log ----" << endl;
            for (int i = 0; i < maxLogSize; i++) {
                if (heartRateLog[i] != 0) {
                    cout << "Log Entry " << i + 1 << ":" << endl;
                    cout << "  Heart Rate: " << heartRateLog[i] << " bpm" << endl;
                    cout << "  Blood Pressure: " << bpLog[i][0] << "/" << bpLog[i][1] << " mmHg" << endl;
                    cout << "  Glucose Level: " << glucoseLog[i] << " mg/dL" << endl;
                    cout << "  Body Temperature: " << tempLog[i] << "°F" << endl;
                }
            }
        } else {
            cout << "System is Off. Please power on the system first." << endl;
        }
    }
};

// Derived Class: EmergencyResponse
class EmergencyResponse : public HealthSystem {
public:
    void triggerAlert() {
        if (isPoweredOn)
            cout << "Emergency Alert Triggered!" << endl;
        else
            cout << "System is Off. Please power on the system first." << endl;
    }

    void sendNotification() {
        if (isPoweredOn)
            cout << "Notification Sent to Caregiver." << endl;
        else
            cout << "System is Off. Please power on the system first." << endl;
    }

    void callEmergencyServices() {
        if (isPoweredOn)
            cout << "Calling Emergency Services..." << endl;
        else
            cout << "System is Off. Please power on the system first." << endl;
    }
};

// Main Function with Interactive Menu
int main() {
    HealthSystem baseSystem;
    VitalSignMonitor vitalMonitor;
    EmergencyResponse emergencyResponse;

    cout << "Enter your name: ";
    string name;
    cin >> name;
    baseSystem.setUserName(name);
    vitalMonitor.setUserName(name);
    emergencyResponse.setUserName(name);

    int choice;
    do {
        cout << "\nSmart Healthcare Assistant Menu:\n";
        cout << "1. Power On System\n";
        cout << "2. Monitor Vital Signs\n";
        cout << "3. Display Vital Signs Log\n";
        cout << "4. Trigger Emergency Alert\n";
        cout << "5. Power Off System\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                baseSystem.powerOn();
                vitalMonitor.isPoweredOn = baseSystem.isPoweredOn;
                emergencyResponse.isPoweredOn = baseSystem.isPoweredOn;
                break;

            case 2:
                cout << "\nMonitoring Vital Signs:\n";
                vitalMonitor.logVitals();
                break;

            case 3:
                vitalMonitor.displayLog();
                break;

            case 4:
                cout << "\nEmergency Response:\n";
                emergencyResponse.triggerAlert();
                emergencyResponse.sendNotification();
                emergencyResponse.callEmergencyServices();
                break;

            case 5:
                baseSystem.powerOff();
                vitalMonitor.isPoweredOn = baseSystem.isPoweredOn;
                emergencyResponse.isPoweredOn = baseSystem.isPoweredOn;
                break;

            case 6:
                cout << "Exiting the system. Stay healthy!" << endl;
                break;

            default:
                cout << "Invalid choice! Please select a valid option." << endl;
        }
    } while (choice != 6);

    return 0;
}
