/*
 * FileReader.cpp
 *
 *  Created on: May 31, 2023
 *      Author: menno
 */

#include "FileReader.hpp"
#include <fstream>
#include "boost/algorithm/string.hpp"
#include <vector>
#include "Logger.hpp"

FileReader::FileReader() : fileName("")
{
}

FileReader::FileReader(const std::string& fileName) : fileName(fileName)
{
}

FileReader::~FileReader()
{
}

void FileReader::setFileName(const std::string& newFileName)
{
	fileName = newFileName;
}

double FileReader::readSettingFromFile(const FileReader::Setting& settingToRead)
{
	switch (settingToRead)
	{
	case FileReader::Setting::COMPASS_STDEV:
		return parseFromFile("stdevCompas");
	break;
	case FileReader::Setting::ODOMETRY_STDEV:
		return parseFromFile("stdevOdometry");
	break;
	case FileReader::Setting::LIDAR_STDEV:
		return parseFromFile("stdevLidar");
	break;
	default:
		return 0;
	break;
	}
}

double FileReader::parseFromFile(const std::string& settingName)
{
	std::fstream file;
	file.open(fileName, std::ios::in);
	std::string setting;
	if (file.is_open())
	{
		for(int lines = 0; std::getline(file, setting); lines++)
		{
			std::vector<std::string> splitLine;
			boost::split(splitLine, setting, boost::is_any_of(":"));

			if (settingName.compare(splitLine.front()) == 0 && splitLine.size() >= minimumWordsOnSettingLine)
			{
				file.close();
				return std::stod(splitLine.at(1));
			}
		}
		file.close();
		Application::Logger::log("Failed read the setting: " + settingName + " from the file: " + fileName);
		return 0;
	}
	else
	{
		Application::Logger::log("Failed to open file with fileName: " + fileName);
		return 0;
	}
}
