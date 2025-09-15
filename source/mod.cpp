#include "draw.h"
#include "patch.h"
#include "mod.h"
#include "gc/OSArena.h"
#include "gc/os.h"
#include "ttyd/dispdrv.h"
#include "ttyd/fontmgr.h"
#include "ttyd/mariost.h"
#include "ttyd/battle_damage.h"
#include "ttyd/battle_unit.h"


void ( * BattleDamageDirect)(int32_t unit_idx, ttyd::battle_unit::BattleWorkUnit* target, ttyd::battle_unit::BattleWorkUnitPart* part, int32_t damage, int32_t fp_damage, uint32_t unk0, uint32_t damage_pattern, uint32_t unk1);

void BattleDamageDirect_new(int32_t unit_idx, ttyd::battle_unit::BattleWorkUnit* target, ttyd::battle_unit::BattleWorkUnitPart* part, int32_t damage, int32_t fp_damage, uint32_t unk0, uint32_t damage_pattern, uint32_t unk1)
{
  gc::os::OSReport("%d target alliance\n", target->alliance);
  if (target->alliance == 0)
  {
    damage *= 2;
    fp_damage *= 2;
  }
  BattleDamageDirect(unit_idx, target, part, damage, fp_damage, unk0, damage_pattern, unk1);
  return;
}


void mod_main()
{
  gc::os::OSReport("%p address\n", ttyd::battle_damage::BattleDamageDirect);
  BattleDamageDirect = hookFunction(ttyd::battle_damage::BattleDamageDirect, BattleDamageDirect_new);
  return;
}