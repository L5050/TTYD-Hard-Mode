#include "evt_cmd.h"
#include "ttyd/evtmgr.h"


namespace mod {

EVT_DECLARE_USER_FUNC(vivian_buff, 0)
EVT_DECLARE(return_from_shadows)
EVT_DECLARE(vivian_woosh)
EVT_DECLARE(hammer_move)
EVT_DECLARE(override_hammer_evt)
EVT_DECLARE(power_bounce)
void mod_main();

}