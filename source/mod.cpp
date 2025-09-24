#include "draw.h"
#include "patch.h"
#include "mod.h"
#include "evt_cmd.h"
#include "ttyd/dispdrv.h"
#include "ttyd/evtmgr.h"
#include "ttyd/fontmgr.h"
#include "ttyd/mariost.h"
#include "ttyd/item_data.h"
#include "ttyd/sac_bakugame.h"
#include "ttyd/battle.h"
#include "ttyd/battle_mario.h"
#include "ttyd/battle_damage.h"
#include "ttyd/battle_unit.h"
#include "ttyd/battle_database_common.h"
#include "ttyd/unit_party_vivian.h"
#include "gc/OSArena.h"
#include "gc/os.h"
#include <gc/types.h>

namespace mod {

ttyd::evtmgr::EvtEntry *( *evtEntry_tramp)(void *evtCode, int32_t executionOrder, uint32_t flags);
ttyd::evtmgr::EvtEntry *( *evtEntryChild_tramp)(ttyd::evtmgr::EvtEntry *parentEvt, void *evtCode, uint32_t flags);
void ( *BtlUnit_GetStatus_tramp)(ttyd::battle_unit::BattleWorkUnit* unit, int8_t status_type, int8_t* turns, int8_t* strength);

void ( * BattleDamageDirect_tramp)(int32_t unit_idx, ttyd::battle_unit::BattleWorkUnit* target, ttyd::battle_unit::BattleWorkUnitPart* part, int32_t damage, int32_t fp_damage, uint32_t unk0, uint32_t damage_pattern, uint32_t unk1);

ttyd::battle_unit::BattleWorkUnit* ( * BtlUnit_Entry_tramp)(ttyd::battle_database_common::BattleUnitSetup* unit_setup);

void BattleDamageDirect_new(int32_t unit_idx, ttyd::battle_unit::BattleWorkUnit* target, ttyd::battle_unit::BattleWorkUnitPart* part, int32_t damage, int32_t fp_damage, uint32_t unk0, uint32_t damage_pattern, uint32_t unk1)
{
  gc::os::OSReport("%d target alliance\n", target->alliance);
  if (target->alliance == 0)
  {
    damage *= 2;
    fp_damage *= 2;
  }
  BattleDamageDirect_tramp(unit_idx, target, part, damage, fp_damage, unk0, damage_pattern, unk1);
  return;
}

ttyd::battle_unit::BattleWorkUnit* BtlUnit_Entry_new(ttyd::battle_database_common::BattleUnitSetup* unit_setup)
{
  ttyd::battle_unit::BattleWorkUnit* unit = BtlUnit_Entry_tramp(unit_setup);
  if (unit->alliance == 1)
  {
    unit->current_hp *= 2;
    unit->max_hp *= 2;
    unit->base_max_hp *= 2;
  }
  return unit;
}

ttyd::evtmgr::EvtEntry *evtEntry_new(void *evtCode, int32_t executionOrder, uint32_t flags)
{
    gc::os::OSReport("%p address\n", evtCode);
    if (evtCode == ttyd::battle_mario::marioAttackEvent_NormalHammer_Core)
    {
        return evtEntry_tramp((void *)override_hammer_evt, executionOrder, flags);
    }
    if (evtCode == ttyd::unit_party_vivian::partyVivianAttack_ShadowGuard)
    {
        gc::os::OSReport("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
        //evtEntry_tramp((void *)veil_buff, 1, 0);
        return evtEntry_tramp(evtCode, executionOrder, flags);
    }
    return evtEntry_tramp(evtCode, executionOrder, flags);
}

void battleUnitGetStatusNew(ttyd::battle_unit::BattleWorkUnit* unit, int8_t status_type, int8_t* turns, int8_t* strength)
{
  BtlUnit_GetStatus_tramp(unit, status_type, turns, strength);
  if (unit->alliance != 1 && status_type == 16 && *strength >= 5)
  {
    *strength = 5;
  }
  return;
}

int clock_out_hit_mario_func(ttyd::evtmgr::EvtEntry* entry, bool firstRun)
{
  ttyd::battle_unit::BattleWorkUnit* unit = ttyd::battle::BattleGetUnitPtr(ttyd::battle::g_BattleWork, 1);
  unit->moves_remaining += 2;
  return 2;
}

int vivian_buff(ttyd::evtmgr::EvtEntry* entry, bool firstRun)
{
  ttyd::battle_unit::BattleWorkUnit* unit = ttyd::battle::BattleGetPartyPtr(ttyd::battle::g_BattleWork);
  unit->moves_remaining += 1;
  return 2;
}

EVT_DECLARE_USER_FUNC(clock_out_hit_mario_func, 0)
EVT_DECLARE_USER_FUNC(vivian_buff, 0)

EVT_BEGIN(veil_buff)
  USER_FUNC(vivian_buff)
RETURN()
EVT_END()

EVT_BEGIN(clock_out_hit_mario_evt)
  USER_FUNC(clock_out_hit_mario_func)
RETURN()
EVT_END()

ttyd::evtmgr::EvtEntry *evtEntryChild_new(ttyd::evtmgr::EvtEntry *parentEvt, void *evtCode, uint32_t flags)
{
  gc::os::OSReport("%p address\n", evtCode);
  if (evtCode == ttyd::sac_bakugame::hitCheck_MarioTeam) {
    return evtEntryChild_tramp(parentEvt, (void *)clock_out_hit_mario_evt, flags);
  }
    if (evtCode == ttyd::battle_mario::marioAttackEvent_NormalHammer_Core) {
    return evtEntryChild_tramp(parentEvt, (void *)override_hammer_evt, flags);
  }
    if (evtCode == ttyd::unit_party_vivian::partyVivianAttack_ShadowGuard) {
      gc::os::OSReport("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
      evtEntry_tramp((void *)veil_buff, 1, 0);
    return evtEntryChild_tramp(parentEvt, (void *)evtCode, flags);
  }
  return evtEntryChild_tramp(parentEvt, evtCode, flags);
}

void patchFunctions()
{
  BattleDamageDirect_tramp = hookFunction(ttyd::battle_damage::BattleDamageDirect, BattleDamageDirect_new);
  BtlUnit_Entry_tramp = hookFunction(ttyd::battle_unit::BtlUnit_Entry, BtlUnit_Entry_new);
  BtlUnit_GetStatus_tramp = hookFunction(ttyd::battle_unit::BtlUnit_GetStatus, battleUnitGetStatusNew);
  evtEntry_tramp = hookFunction(ttyd::evtmgr::evtEntry, evtEntry_new);
  evtEntryChild_tramp = hookFunction(ttyd::evtmgr::evtChildEntry, evtEntryChild_new);
  return;
}

void patchItems()
{
  ttyd::item_data::itemDataTable[ttyd::item_data::ItemType::PEEKABOO].bp_cost = 0;
  ttyd::item_data::itemDataTable[ttyd::item_data::ItemType::POWER_RUSH].bp_cost = 3;
  ttyd::item_data::itemDataTable[ttyd::item_data::ItemType::LAST_STAND].bp_cost = 20;
  ttyd::item_data::itemDataTable[ttyd::item_data::ItemType::PRETTY_LUCKY].bp_cost = 30;
  ttyd::item_data::itemDataTable[ttyd::item_data::ItemType::LUCKY_DAY].bp_cost = 30;
  ttyd::item_data::itemDataTable[ttyd::item_data::ItemType::QUICK_CHANGE].bp_cost = 0;
  ttyd::item_data::itemDataTable[ttyd::item_data::ItemType::HAMMER_THROW].bp_cost = 2;
  ttyd::item_data::itemDataTable[ttyd::item_data::ItemType::PITY_FLOWER].bp_cost = 0;
  return;
}


void mod_main()
{
  patchFunctions();
  patchItems();
  return;
}

}