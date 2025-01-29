#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // For sleep() on Unix; use Windows.h for Sleep() on Windows

using namespace std;

int main() {
    srand(time(nullptr)); // Seed random number generator

    // Threshold levels (percentage)
    const int LOW = 20;
    const int MEDIUM = 50;
    const int HIGH = 80;
    const int CRITICAL = 95;

    bool pumpOn = false;
    bool alarmOn = false;
    int waterLevel;

    while(true) {
        // Simulate water level reading (0-100%)
        waterLevel = rand() % 101;

        cout << "\nWater Level: " << waterLevel << "%" << endl;

        // Check thresholds and take action
        if(waterLevel >= CRITICAL) {
            cout << "CRITICAL LEVEL! Activating emergency protocols!" << endl;
            pumpOn = true;
            alarmOn = true;
        } else if(waterLevel >= HIGH) {
            cout << "High level detected - activating pump" << endl;
            pumpOn = true;
            alarmOn = false;
        } else if(waterLevel >= MEDIUM) {
            cout << "Medium level - system normal" << endl;
            pumpOn = false;
            alarmOn = false;
        } else if(waterLevel >= LOW) {
            cout << "Low level - monitoring" << endl;
            pumpOn = false;
            alarmOn = false;
        } else {
            cout << "Very low level - check water supply" << endl;
            pumpOn = false;
            alarmOn = false;
        }

        // Display system status
        cout << "Pump: " << (pumpOn ? "ON" : "OFF") << endl;
        cout << "Alarm: " << (alarmOn ? "ACTIVE" : "INACTIVE") << endl;

        sleep(1); // 1-second delay between readings
    }

    return 0;
}