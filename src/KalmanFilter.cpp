/*
 * KalmanFilter.cpp
 *
 *  Created on: May 29, 2023
 *      Author: menno
 */

#include "KalmanFilter.hpp"
#include "Odometry.hpp"
#include "Compass.hpp"
#include <cmath>

KalmanFilter::KalmanFilter()
{
}

KalmanFilter::~KalmanFilter()
{
}

void KalmanFilter::initValues(const wxPoint& startPosition)
{
	belief = startPosition;
	A = { { 1, 0 }, { 0, 1 } };
	Xk_1 = {(double)belief.x, (double)belief.y};
	B = { { 1, 0 }, { 0, 1 } };
	Wk = { 0, 0 };
	Pk_1 = { { 100, 0 }, { 0, 100 } };
	Qk = { { 1, 0 }, { 0, 1 } };
	H = { { 1, 0 }, { 0, 1 } };
	R = { { 5, 0}, { 0, 5 } };
	C = { { 1, 0 }, { 0, 1 } };
	Z = { 0, 0 };
}

void KalmanFilter::calculatePosition(const wxPoint& position, const double& odometryMeasurement, const double& compassMeasurement)
{
	calculatePredictedStateVector(position);
	calculatePredictedCovarianceMatrix();
	calculateMeasurementUpdate(odometryMeasurement, compassMeasurement);
	calculateKalmanGain();
	calculateAdjustedStateVector();
	calculateAdjustedProcessCovariance();

	belief = wxPoint((int)Xk_1[0][0], (int)Xk_1[1][0]);
	drivenRoute.push_back(belief);
}

std::vector<wxPoint> KalmanFilter::getDrivenRoute()
{
	return drivenRoute;
}

void KalmanFilter::calculatePredictedStateVector(const wxPoint& position)
{
	/**
	 * Xkp = X * Xk_1 + B * Uk + Wk
	 *
	 * where:
	 * Xkp = The predicted state vector
	 * A = Transition matrix without updates
	 * Xk_1 = previous state vector
	 * B = Transition matrix with updates
	 * Uk = control vector
	 * Wk = Predicted process noice vector
	 */
	Matrix<double, 2, 1> Uk = {static_cast<double>(position.x - Xk_1[0][0]), static_cast<double>(position.y - Xk_1[1][0])};
	Xkp = A * Xk_1 + B * Uk + Wk;
}

void KalmanFilter::calculatePredictedCovarianceMatrix()
{
	/**
	 * Pkp = A * Pk_1 * AT + Qk
	 *
	 * Where:
	 * Pkb = The predicted covariance matrix
	 * A = Transition Matrix without updates
	 * Pk_1 = previous process covariance matrix
	 * AT = Transpose of A
	 * Qk = Process noice covariance matrix
	 */
	Pkp = A * Pk_1 * A.transpose() + Qk;

}

void KalmanFilter::calculateKalmanGain()
{
	/**
	 * K = (Pkp * H) / (H * Pkp * Ht + R)
	 *
	 * Where:
	 * K = Kalman gain
	 * Pkb = The predicted covariance matrix (see calculatePredictedCovarianceMatrix)
	 * H = Matrix to remove differences
	 * Ht = Transpose of H
	 * R = sensor covariance matrix
	 */
	// Instead of deviding multiply by by the inverse. Deviding will give an error.
	K = (Pkp * H) * ((H * Pkp * H.transpose()) + R).inverse();
}

void KalmanFilter::calculateMeasurementUpdate(const double& distanceDriven, const double& compassData)
{
	/**
	 * Yt = C * Xkm + Zk
	 */
	Matrix<double, 2, 1> measurementData = { distanceDriven * -std::cos(compassData), distanceDriven * -std::sin(compassData) };
	Matrix<double, 2, 1> Xkm = Xk_1 + measurementData;
	Yt = C * Xkm + Z;
}

void KalmanFilter::calculateAdjustedStateVector()
{
	/**
	 * Xk = Xkp + K * (Yt - H * Xkp)
	 *
	 * Where:
	 * Xk = Adjusted state vector
	 * Xkp = The predicted state vector
	 * K = Kalman gain
	 * Yt = Measurement vector
	 * H = Matrix to remove differences
	 */
	Xk_1 = Xkp + K * (Yt - H * Xkp);
}

void KalmanFilter::calculateAdjustedProcessCovariance()
{
	/**
	 * Pk = (I - K * H) * Pkp
	 *
	 * Where:
	 * Pk = Adjusted process covariance matrix
	 * I = Identity matrix
	 * K = Kalman Gain
	 * H = Matrix to remove differences
	 * Pkp = The predicted covariance matrix
	 */
	Pk_1 = (K.identity() - K * H) * Pkp;
}

void KalmanFilter::clearDrivenRoute()
{
	drivenRoute.clear();
}

wxPoint KalmanFilter::getBelief() const
{
		return belief;
}

void KalmanFilter::setBelief(wxPoint belief)
{
	this->belief = belief;
}

