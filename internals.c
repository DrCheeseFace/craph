#include <SDL3/SDL.h>
#include <stdint.h>

#include "internals.h"

SDL_Color colors[COLOR_COUNT] = {
	{ UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX }, //white
	{ 0, 0, 0, 0 }, //black
	{ 255, 0, 0, 255 }, //red
	{ 0, 255, 0, 255 }, //green
	{ 0, 0, 255, 0 }, //blue
	{ 255, 255, 0, 255 }, // yellow
	{ 255, 0, 255, 255 }, // magenta
};
