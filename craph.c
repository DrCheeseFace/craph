#include <SDL3/SDL.h>

#include "./mr_utils/mrm_misc.h"
#include "bar_barchart.h"
#include "internals.h"

#include <stdlib.h>

global_variable Bool sdl_inited = FALSE;
global_variable uint sdl_active_charts = 0;

CraphChart *craph_barchart_create(uint width, uint height, BarChart *bar_chart)
{
	(void)bar_chart;

	if (sdl_inited == FALSE) {
		SDL_Init(SDL_INIT_VIDEO);
	}

	SDL_Surface *surface =
		SDL_CreateSurface(width, height, SDL_PIXELFORMAT_RGBA8888);

	SDL_Renderer *renderer = SDL_CreateSoftwareRenderer(surface);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

	SDL_FRect rect = { .h = 100, .w = 100, .x = 50, .y = 50 };
	SDL_RenderFillRect(renderer, &rect);

	SDL_RenderPresent(renderer);

	CraphChart *chart = malloc(sizeof(*chart));

	chart->renderer = renderer;
	chart->surface = surface;

	chart->type = CRAPH_CHART_TYPE_BAR_CHART;

	sdl_active_charts++;

	return chart;
}

void craph_chart_destroy(CraphChart *chart)
{
	SDL_DestroyRenderer(chart->renderer);
	SDL_DestroySurface(chart->surface);
	free(chart);

	if (sdl_active_charts == 1) {
		SDL_Quit();
	}

	sdl_active_charts--;
}

void craph_chart_display(CraphChart *chart)
{
	(void)chart;
}

Err craph_chart_save(CraphChart *chart, const char *file_path)
{
	//TODO err handling
	SDL_SaveBMP(chart->surface, file_path);

	return OK;
}
