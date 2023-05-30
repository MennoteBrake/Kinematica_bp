#include "MathUtils.hpp"
#include <random>

namespace Utils
{
	/**
	 *
	 */
	// cppcheck-suppress unusedFunction
	/* static */ double MathUtils::toRadians( double aDegrees)
	{
		return aDegrees * PI / 180.0;
	}
	/**
	 *
	 */
	// cppcheck-suppress unusedFunction
	/* static */ double MathUtils::toDegrees( double aRadian)
	{
		return aRadian * 180.0 / PI;
	}

	/* static */ double MathUtils::deviateData(const double& stdev, const double& data)
	{
		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_real_distribution<double> uni((stdev * -1), stdev);
		return (data + uni(rng));
	}
} //namespace Utils
