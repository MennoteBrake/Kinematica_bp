/*
 * Compass.hpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#ifndef SRC_COMPASS_HPP_
#define SRC_COMPASS_HPP_

#include "BoundedVector.hpp"

class Compass {
public:
	Compass(double stdev);
	virtual ~Compass();

	double getDirection(const Model::BoundedVector& direction);
private:
	double stdev;
};

#endif /* SRC_COMPASS_HPP_ */
