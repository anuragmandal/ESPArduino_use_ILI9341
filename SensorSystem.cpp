#include "SensorSystem.h"
#include "Display.h"
#include <iostream>
#include <stdexcept>


SensorSystem::SensorSystem() : temperature(0), waterLevel(0) , moisture(0)
{

}

float SensorSystem::getTemperature() const
{
  return temperature;
}

void SensorSystem::setTemperature(float temp)
{
  if(temp < -100 || temp > 100)
  {
    throw std::invalid_argument("Temperature must be within a realistic range.");
  }
  temperature = temp;
}

float SensorSystem::getWaterLevel() const
{
  return waterLevel;
}

void SensorSystem::setWaterLevel(float level) 
{
  if(level < 0 || level > 100) { // Example range check
        throw std::invalid_argument("Water level must be between 0 and 100.");
    }
   waterLevel = level;
}

float SensorSystem::getMoisture() const
{
  return moisture;
}

void SensorSystem::setMoisture(float moist)
{
  if(moist < 0 || moist > 100) { // Example range check
        throw std::invalid_argument("Moisture must be between 0 and 100.");
  }
  moisture = moist;
}

// Method to display status
void SensorSystem::displayData() const {
    displayText(0, 40, "Status: IDLE", WHITE);
    
    char buffer[30];

    snprintf(buffer, sizeof(buffer), "Moisture: %.0f%%", moisture);
    displayText(0, 80, buffer, WHITE);

    snprintf(buffer, sizeof(buffer), "Water: %.0f%%", waterLevel);
    displayText(0, 120, buffer, WHITE);

    snprintf(buffer, sizeof(buffer), "Temp: %.1f C", temperature);
    displayText(0, 160, buffer, WHITE);
}



