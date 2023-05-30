#ifndef MATHUTILS_HPP_
#define MATHUTILS_HPP_

#include "Config.hpp"

namespace Utils
{
	/**
	 *
	 */
	const double PI = 3.141592654;
	/**
	 *
	 */
	const double ALMOST_ZERO = 0.000000000000001;

	/**
	 *
	 */
	class MathUtils
	{
		public:
			/**
			 *
			 */
			static double toRadians( double aDegrees);
			/**
			 *
			 */
			static double toDegrees( double aRadian);

			/**
			 * @brief Uses STDEV to transform data
			 *
			 * @param stdev the standard deviation to use
			 * @param data the data to transform
			 *
			 * @return deviated data
			 */
			static double deviateData(const double& stdev, const double& data);
	}; // class Math
}// namespace Utils
#endif // MATHUTILS_HPP_
