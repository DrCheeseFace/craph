#ifndef INTERNALS_H
#define INTERNALS_H

#include <SDL3/SDL_pixels.h>

typedef enum {
	CRAPH_CHART_TYPE_BAR_CHART,
	CRAPH_CHART_TYPE_COUNT
} CraphChartType;

typedef struct {
	void *renderer;
	void *surface;
	CraphChartType type;
} CraphChart;

typedef enum {
	COLOR_WHITE = 0,
	COLOR_BLACK,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_BLUE,
	COLOR_YELLOW,
	COLOR_MAGENTA,
	COLOR_COUNT
} Color;

extern SDL_Color colors[COLOR_COUNT];

#endif // !INTERNALS_H
