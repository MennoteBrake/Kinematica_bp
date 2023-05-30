/*
 * Lidar.hpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#ifndef SRC_LIDAR_HPP_
#define SRC_LIDAR_HPP_
#include <vector>
#include "Point.hpp"

class Lidar {
public:
	Lidar();
	Lidar(double stdev);
	virtual ~Lidar();

	std::vector<double> measureDistance(const wxPoint& robotPosition);
private:
	double stdev;
	const uint8_t amountOfLidarBeams = 180;
};

#endif /* SRC_LIDAR_HPP_ */
