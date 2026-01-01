#pragma once
#include <string>
#include <sstream>
#include <iomanip>

namespace util
{
	// Meters to yards.
	constexpr float mtoyard(float m)
	{
		return m * 1.094f;
	}

	inline std::string Float2String(const float in, unsigned char precision = 2)
	{
		std::ostringstream stream;
		stream << std::fixed << std::setprecision(precision) << in;
		return stream.str();
	}

	inline std::string makeDist(float dist, const bool units)
	{
		// 1 Unit of distance = 1 meter.
		switch (units)
		{
		case 0:
			if (dist > 999)
			{
				return Float2String(dist / 1000, 1) + " KM";
			}
			else
			{
				return Float2String(dist, 0) + " m";
			}
			break;
		case 1:
			dist = mtoyard(dist);
			if (dist > 599)
			{
				return Float2String(dist / 1760, 1) + " Mi";
			}
			else
			{
				return Float2String(dist, 0) + " yrds";
			}
			break;
		}
		return "";
	}
} // namespace util