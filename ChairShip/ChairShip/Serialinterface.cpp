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
			mySerial = new serial::Serial(port, 9600, serial::Timeout::simpleTimeout(250)); //maybe change 9600 to 115200?

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
	if (connected) 
	{
		//Write to the monitor to get reading
		//send("P");
		mySerial->write("P");

		//Get result from accelerometer
		std::string result = mySerial->readline();
		//std::cout << result << std::endl;

		//Split result string into each axis reading
		std::vector <std::string> readings = splitString(result, ';');

		//Convert each token to float and assign to variable
		x = std::stof(readings[0]);
		y = std::stof(readings[1]);
		z = std::stof(readings[2]);

		if (result != "") 
		{
		}
	}
}

void SerialInterface::close()
{
	mySerial->flush();
	mySerial->close();
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
