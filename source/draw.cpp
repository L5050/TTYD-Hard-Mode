#include "draw.h"
#include "ttyd/dispdrv.h"
#include "ttyd/fontmgr.h"

#include <cstdint>

// Simple function to register any given function to run when the vanilla game's drawing functions run. Sets up the function to
// run on the debug layer, which makes it so that everything drawn in it is drawn on top of everything else that the vanilla
// game draws.
void drawOnDebugLayer(ttyd::dispdrv::PFN_dispCallback func, float order)
{
    ttyd::dispdrv::dispEntry(ttyd::dispdrv::CameraId::kDebug3d, 2, order, func, nullptr);
}

// Simple function for drawing text. Would need to be modified to properly handle multi-line text, and a function other than
// `FontDrawString` would need to be used to make use of the vanilla game's text commands.
void drawText(const char *text, float posX, float posY, float scale, uint32_t color)
{
    // Initalize text drawing
    drawTextInit(true, 0xFF);

    // Set the text color and scale
    ttyd::fontmgr::FontDrawColor(reinterpret_cast<uint8_t *>(&color));
    ttyd::fontmgr::FontDrawScale(scale);

    // Draw the text
    ttyd::fontmgr::FontDrawString(posX, posY, text);
}
