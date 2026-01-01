#include "Config.h"

namespace util
{
	inline bool CheckBMX(const Config& cfg, const CPed *player)
	{
		if (cfg.ENABLE_BMX)
			return false;

		return player->m_pVehicle->m_nVehicleSubClass == VEHICLE_BMX;
	}

	inline bool NavEnabled(const Config& cfg, const CPed *player)
	{
		// Check if player is in a vehicle using bInVehicle flag
		// In plugin-sdk, use m_nPedFlags.bInVehicle or IsInVehicle() method
		bool inVehicle = player && player->m_pVehicle && player->bInVehicle;

		return (inVehicle &&
				player->m_pVehicle->m_nVehicleSubClass != VEHICLE_PLANE &&
				player->m_pVehicle->m_nVehicleSubClass != VEHICLE_HELI &&
				!CTheScripts::bMiniGameInProgress &&
				!CheckBMX(cfg, player));
	}
} // namespace util