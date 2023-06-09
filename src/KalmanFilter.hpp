/*
 * KalmanFilter.hpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#ifndef SRC_KALMANFILTER_HPP_
#define SRC_KALMANFILTER_HPP_

#include "Matrix.hpp"
#include "Point.hpp"


class KalmanFilter {
public:
	/**
	 * Constructs a KalmanFilter object
	 */
	KalmanFilter();
	virtual ~KalmanFilter();

	/**
	 * Initializes the different matrices.
	 */
	void initValues(const wxPoint& startPosition);
	/**
	 * Calculates the belief, and runs the kalman filter.
	 */
	void calculatePosition(const wxPoint& position, const double& odometryMeasurement, const double& compassMeasurement);

	/**
	 * Getter for the driven route.
	 */
	std::vector<wxPoint> getDrivenRoute() const;
	/**
	 * Clears the driven route.
	 */
	void clearDrivenRoute();
	/**
	 * Getter for the belief.
	*/
	wxPoint getBelief() const;
	/**
	 * Setter for the belief.
	 */
	void setBelief(wxPoint belief);

private:
	void calculatePredictedStateVector(const wxPoint& position);
	void calculatePredictedCovarianceMatrix();
	void calculateKalmanGain();
	void calculateMeasurementUpdate(const double& distanceDriven, const double& compassData);
	void calculateAdjustedStateVector();
	void calculateAdjustedProcessCovariance();

	std::vector<wxPoint> drivenRoute;
	wxPoint belief;
	Matrix<double, 2, 2> A;
	Matrix<double, 2, 1> Xk_1;
	Matrix<double, 2, 2> B;
	Matrix<double, 2, 1> Wk;
	Matrix<double, 2, 1> Xkp;
	Matrix<double, 2, 2> Pk_1;
	Matrix<double, 2, 2> Qk;
	Matrix<double, 2, 2> H;
	Matrix<double, 2, 2> R;
	Matrix<double, 2, 1> Yt;
	Matrix<double, 2, 2> C;
	Matrix<double, 2, 1> Z;
	Matrix<double, 2, 2> Pkp;
	Matrix<double, 2, 2> K;
};

#endif /* SRC_KALMANFILTER_HPP_ */




