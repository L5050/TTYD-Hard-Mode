#pragma once

#include "evtmgr.h"

#include <cstdint>

namespace ttyd::sac_bakugame {

extern "C" {

EVT_DECLARE(marioAttackEvent_BakuGame)
EVT_DECLARE(hitCheck_MarioTeam)
EVT_DECLARE(hitCheck_EnemyTeam)
EVT_DECLARE(hitCheck_AudienceTeam)

// bakuGameDispStar
// bakuGameDisp3D
// bakuGameDisp2D
// bakuGameAudienceSurprise
// bakuGameEnemySurprise
// bakuGameMarioSurprise
// bakuGameAudienceSurpriseReset
// bakuGameEnemySurpriseReset
// bakuGameMarioSurpriseReset
// bakuGameAudienceCanThrowPos
// bakuGamePartyExist
// bakuGameDecideButton
// bakuGameHeihoReturn
// bakuGameMain
// bakuGameBombEntry
EVT_DECLARE_USER_FUNC(bakuGameDecideWeapon, 3)
// end_bakugame
// init_bakugame
// main_star
// star_stone_appear
// GetBakuGamePtr

}

}