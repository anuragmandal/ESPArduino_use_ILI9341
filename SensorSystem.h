#ifndef SENSORSYSTEM_H
#define SENSORSYSTEM_H

class SensorSystem
{
  private:
  float temperature;
  float waterLevel;
  float moisture;


  public:
  SensorSystem();
  float getTemperature() const;
  void setTemperature(float temp);

  float getWaterLevel() const;
  void setWaterLevel(float level);

  float getMoisture() const;
  void setMoisture(float moist);


  void displayData() const;
};

#endif