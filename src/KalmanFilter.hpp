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
	KalmanFilter();
	virtual ~KalmanFilter();

	void initValues(wxPoint startPosition);
	void calculatePosition(wxPoint position, const double& odometryMeasurement, const double& compassMeasurement);

	std::vector<wxPoint> getDrivenRoute();

private:
	void calculatePredictedStateVector(wxPoint position);
	void calculatePredictedCovarianceMatrix();
	void calculateKalmanGain();
	void calculateMeasurementUpdate(double distanceDriven, double compassData);
	void calculateAdjustedStateVector();
	void calculateAdjustedProcessCovariance();

	std::vector<wxPoint> drivenRoute;
	wxPoint belief;
	Matrix<double, 2, 2> A;// = { { 1, 0 }, { 0, 1 } };
	Matrix<double, 2, 1> Xk_1;// = { static_cast<double>(belief.x), static_cast<double>(belief.y) };
	Matrix<double, 2, 2> B;// = { { 1, 0 }, { 0, 1 } };
	Matrix<double, 2, 1> Wk;// = { 0, 0 };
	Matrix<double, 2, 1> Xkp;
	Matrix<double, 2, 2> Pk_1;// = { { 100, 0 }, { 0, 100 } };
	Matrix<double, 2, 2> Qk;// = { { 25, 0 }, { 0, 25 } };
	Matrix<double, 2, 2> H;// = { { 1, 0 }, { 0, 1 } };
	Matrix<double, 2, 2> R;// = { { 4, 0 }, { 0, 4 } };
	Matrix<double, 2, 1> Yt;
	Matrix<double, 2, 2> C;// = { { 1, 0 }, { 0, 1 } };
	Matrix<double, 2, 1> Z;// = { 0, 0 };
	Matrix<double, 2, 2> Pkp;
	Matrix<double, 2, 2> K;
};

#endif /* SRC_KALMANFILTER_HPP_ */




