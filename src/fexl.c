#include "die.h"
#include "value.h"
#include "basic.h"
#include "eval.h"
#include "long.h"
#include "parse_file.h"
#include "resolve.h"
#include "run.h"
#include "string.h"

/*
This is the main routine of the Fexl interpreter.  The exit status is 0 for
success, or 1 for failure.

It parses the file named on the command line, or stdin if no name is given, and
evaluates that function.
*/

/*TODO NOW update fexl_resolve to return just the resolution function so
we can chain it.  Also update a1.fxl to demonstrate the new technique instead
of the old crap. */

int main(int argc, char *argv[], char *envp[])
	{
	beg_run(argc, argv, envp);

	value result = parse_file(argc > 1 ? argv[1] : 0);
	int ok = result->L->R->T == fexl_C;
	value f = result->R->L->R;

	if (!ok)
		warn(string_data(f));

	value symbols = result->R->R;

	while (symbols->L)
		{
		value entry = symbols->L->R;
		value sym = entry->L->R;
		value def = resolve(sym);

		if (def)
			f = A(f,def);
		else
			{
			value place = entry->R;
			line = get_long(place);
			warn("Undefined symbol %s",string_data(sym));
			ok = 0;
			}

		symbols = symbols->R;
		}

	hold(result);
	drop(result);
	hold(f);

	if (ok)
		eval(f);
	else
		main_exit = 1;

	drop(f);

	end_value();
	return main_exit;
	}
