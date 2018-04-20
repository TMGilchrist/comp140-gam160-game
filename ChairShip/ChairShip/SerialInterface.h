#pragma once
#include <serial\serial.h>

class SerialInterface 
{
public:
	SerialInterface();
	~SerialInterface() {};

	//Write a message to the serial monitor
	void send(std::string message);

	//Get an accelerometer reading
	void getData();

	//Split a string into tokens based on a delimiter. Code sourced from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
	std::vector<std::string> splitString(const std::string& string, char delimiter);

private:
	//If the serial interface is connected
	bool connected = false;

	//Axis readings. Normalised, m/s^2
	float xReading;
	float yReading;
	float zReading;

	//Serial interface
	serial::Serial* mySerial;

};