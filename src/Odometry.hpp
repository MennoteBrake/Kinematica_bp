/*
 * Odometry.hpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#ifndef SRC_ODOMETRY_HPP_
#define SRC_ODOMETRY_HPP_

class Odometry {
public:
	Odometry();
	Odometry(double stdev);
	virtual ~Odometry();

	double measureOdometry(double speed);

private:
	double stdev;
};

#endif /* SRC_ODOMETRY_HPP_ */
