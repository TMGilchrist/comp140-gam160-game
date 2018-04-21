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

	void close();

	//Split a string into tokens based on a delimiter. Code sourced from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
	std::vector<std::string> splitString(const std::string& string, char delimiter);

	//Getters
	float getX()
	{
		return x;
	}
	float getY() 
	{
		return y;
	}
	float getZ() 
	{
		return z;
	}

private:
	//If the serial interface is connected
	bool connected = false;

	//Axis readings. Normalised, m/s^2
	float x;
	float y;
	float z;

	//Serial interface
	serial::Serial* mySerial;

};