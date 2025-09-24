#ifndef BAR_BARCHART_H
#define BAR_BARCHART_H

#include "mr_utils/mrm_misc.h"
#include "mr_utils/mrs_strings.h"

#include "utils.h"

#include <stdint.h>

typedef struct {
	MrsString label;
	int value;
	struct color color;
} Bar;

typedef struct {
	MrsString title;
	MrsString row_title;
	MrsString column_title;

	Bar **bars;
	uint bars_count;
} BarChart;

Bar *bar_bar_create(const char *label, int value, struct color color);

void bar_bar_destroy(Bar *bar);

BarChart *bar_barchart_create(const char *title, const char *row_title,
			       const char *column_title, Bar **bars,
			       uint bars_count);

void bar_barchart_destroy(BarChart *bar_chart);

// TODO?
// typedef enum {
// 	BAR_VALUE_LABEL_LOCATION_COUNT
// } BarValueLabelLocation;

#endif // !BAR_BARCHART_H
