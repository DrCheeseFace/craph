#ifndef CRAPH_H
#define CRAPH_H

#include <SDL3/SDL.h>

#include "bar_barchart.h"
#include "mr_utils/mrm_misc.h"

typedef void CraphChart;

CraphChart *craph_barchart_create(uint width, uint height,
				     BarChart *bar_chart);

void craph_chart_destroy(CraphChart* chart);

void craph_chart_display(CraphChart *chart);

Err craph_chart_save(CraphChart *renderer, const char *file_path);

#endif // !CRAPH_H
