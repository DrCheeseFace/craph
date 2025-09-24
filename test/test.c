#include "../craph.h"

#include "../mr_utils/mrd_debug.h"
#include "../mr_utils/mrl_logger.h"
#include "../mr_utils/mrt_test.h"


Err test_test(MrlLogger *logger)
{
	MrtContext *t_ctx = mrt_ctx_create("test_test", logger);

	mrt_ctx_append_case(t_ctx, "test test", 1 == 1);

	craph_barchart_create(200, 200, NULL);

	Err err = mrt_ctx_log(t_ctx);
	mrt_ctx_destroy(t_ctx);
	return err;
}

int main(void)
{
	MrlLogger *logger = mrl_create(stderr, TRUE, FALSE);

	Err err = OK;

	err = err || test_test(logger);

	mrl_destroy(logger);

	return err;
}
