#include "value.h"
#include "double.h"
#include "long.h"
#include "string.h"

value type_long(value f) { return 0; }

/* Make a new value of type long.  */
value Qlong(long number)
	{
	value f = D(type_long);
	f->R->L = (value)number;
	return f;
	}

long get_long(value f)
	{
	return (long)f->R->L;
	}

value fexl_long_add(value f)
	{
	if (!f->L || !f->L->L) return 0;

	value x = f->L->R;
	value y = f->R;

	if (!arg(type_long,x)) return 0;
	if (!arg(type_long,y)) return 0;

	return Qlong(get_long(x) + get_long(y));
	}

value fexl_long_sub(value f)
	{
	if (!f->L || !f->L->L) return 0;

	value x = f->L->R;
	value y = f->R;

	if (!arg(type_long,x)) return 0;
	if (!arg(type_long,y)) return 0;

	return Qlong(get_long(x) - get_long(y));
	}

value fexl_long_mul(value f)
	{
	if (!f->L || !f->L->L) return 0;

	value x = f->L->R;
	value y = f->R;

	if (!arg(type_long,x)) return 0;
	if (!arg(type_long,y)) return 0;

	return Qlong(get_long(x) * get_long(y));
	}

/* long_div returns 0 if you try to divide by 0. */
value fexl_long_div(value f)
	{
	if (!f->L || !f->L->L) return 0;

	value x = f->L->R;
	value y = f->R;

	if (!arg(type_long,x)) return 0;
	if (!arg(type_long,y)) return 0;

	long vx = get_long(x);
	long vy = get_long(y);

	return Qlong(vy ? vx / vy : 0);
	}

/* Determine if the value has type long. */
value fexl_is_long(value f)
	{
	return arg_is_type(type_long,f);
	}

/* Convert long to double. */
value fexl_long_double(value f)
	{
	if (!f->L) return 0;

	value x = f->R;
	if (!arg(type_long,x)) return 0;

	return Qdouble(get_long(x));
	}

/* Convert long to string. */
extern int sprintf(char *str, const char *format, ...);
value fexl_long_string(value f)
	{
	if (!f->L) return 0;

	value x = f->R;
	if (!arg(type_long,x)) return 0;

	char buf[100]; /* being careful here */
	sprintf(buf, "%ld", get_long(x));
	return Qcopy_string(buf);
	}

/* Convert long to char (string of length 1). */
value fexl_long_char(value f)
	{
	if (!f->L) return 0;

	value x = f->R;
	if (!arg(type_long,x)) return 0;

	char buf[1];
	buf[0] = get_long(x);
	return Qcopy_chars(buf,1);
	}

/* long_compare x y lt eq gt */
value fexl_long_compare(value f)
	{
	if (!f->L || !f->L->L || !f->L->L->L || !f->L->L->L->L
		|| !f->L->L->L->L->L)
		return 0;

	value x = f->L->L->L->L->R;
	value y = f->L->L->L->R;

	if (!arg(type_long,x)) return 0;
	if (!arg(type_long,y)) return 0;

	long vx = get_long(x);
	long vy = get_long(y);

	if (vx < vy) return f->L->L->R;
	if (vx > vy) return f->R;
	return f->L->R;
	}
