/*
 * FileReader.hpp
 *
 *  Created on: May 31, 2023
 *      Author: menno
 */

#ifndef SRC_FILEREADER_HPP_
#define SRC_FILEREADER_HPP_

#include <string>

class FileReader {
public:
	enum Setting
	{
		COMPASS_STDEV = 0,
		ODOMETRY_STDEV,
		LIDAR_STDEV
	};

	/**
	 * @brief constructs FileReader object with filename == ""
	 */
	FileReader();
	/**
	 * @brief constructs a FileReader with the given fileName
	 *
	 * @param fileName the name of the file to open
	 */
	FileReader(const std::string& fileName);
	/**
	 * @brief Destructor
	 */
	virtual ~FileReader();
	/**
	 *	@brief sets the FileName
	 *
	 *	@param newFileName the new fileName
	 */
	void setFileName(const std::string& newFileName);
	/**
	 * @brief Reads a setting from the file
	 *
	 * @param settingToRead The setting to read
	 */
	double readSettingFromFile(const Setting& settingToRead);

private:

	double parseFromFile(const std::string& settingName);

	std::string fileName;
	const uint8_t minimumWordsOnSettingLine = 2;
};

#endif /* SRC_FILEREADER_HPP_ */
