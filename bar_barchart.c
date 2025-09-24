#include "mr_utils/mrd_debug.h"
#include "mr_utils/mrs_strings.h"

#include "bar_barchart.h"

#include <stdlib.h>
#include <string.h>

Bar *bar_bar_create(const char *label, int value, struct color color)
{
	Bar *bar = malloc(sizeof(*bar));

	mrs_init(strlen(label), label, strlen(label), &bar->label);
	bar->value = value;
	bar->color = color;

	return bar;
}

void bar_bar_destroy(Bar *bar)
{
	mrs_free(&bar->label);
	free(bar);
}

BarChart *bar_barchart_create(const char *title, const char *row_title,
			       const char *column_title, Bar **bars,
			       uint bars_count)
{
	BarChart *bar_chart = malloc(sizeof(*bar_chart));

	mrs_init(strlen(title), title, strlen(title), &bar_chart->title);
	mrs_init(strlen(row_title), row_title, strlen(row_title),
		 &bar_chart->row_title);
	mrs_init(strlen(column_title), column_title, strlen(column_title),
		 &bar_chart->column_title);

	bar_chart->bars = bars;
	bar_chart->bars_count = bars_count;

	return bar_chart;
}

void bar_barchart_destroy(BarChart *bar_chart)
{
	for (uint i = 0; i < bar_chart->bars_count; i++) {
		bar_bar_destroy(bar_chart->bars[i]);
	}

	mrs_free(&bar_chart->title);
	mrs_free(&bar_chart->row_title);
	mrs_free(&bar_chart->column_title);

	free(bar_chart);
}
