#include "stdafx.h"
#include "SerialInterface.h"

SerialInterface::SerialInterface()
{
	//Open serial ports
	std::vector <serial::PortInfo> devicesFound = serial::list_ports();
	std::vector <serial::PortInfo>::iterator iter = devicesFound.begin();

	//Check all open ports
	while (iter != devicesFound.end())
	{
		serial::PortInfo device = *iter++;
		std::string port = device.port.c_str();

		try
		{
			mySerial = new serial::Serial(port, 9200, serial::Timeout::simpleTimeout(250)); //maybe change 9200 to 115200?

			if (mySerial->isOpen())
			{
				std::cout << "Connection success: " << port << "\n";
				connected = true;

				break;
			}
		}

		catch (std::exception &e)
		{

		}
	}
}

void SerialInterface::send(std::string message)
{
	if (connected)
	{
		mySerial->write(message);
	}
}

void SerialInterface::getData()
{
	//Write to the monitor to get reading
	send("P");

	//Get result from accelerometer
	std::string result = mySerial->readline();

	//Split result string into each axis reading
	std::vector <std::string> readings = splitString(result, ';');

	//Convert each token to float and assign to variable
	xReading = std::stof(readings[0]);
	yReading = std::stof(readings[1]);
	zReading = std::stof(readings[2]);
}

std::vector<std::string> SerialInterface::splitString(const std::string & string, char delimiter)
{
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(string);

		while (std::getline(tokenStream, token, delimiter))
		{
			tokens.push_back(token);
		}

		return tokens;
}
