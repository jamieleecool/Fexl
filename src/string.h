extern value type_string(value);
extern value Qchars(const char *data, long len);
extern value Qcopy_chars(const char *data, long len);
extern value Qcopy_string(const char *data);
extern value Qstring(const char *data);
extern char *string_data(value);
extern long string_len(value);
extern int string_eq(value, value);
extern int string_long(char *beg, long *num);
extern int string_double(char *beg, double *num);
extern value fexl_is_string(value);
extern value fexl_string_compare(value);
extern value fexl_string_slice(value);
extern value fexl_string_append(value);
extern value fexl_string_len(value);
extern value fexl_string_long(value);
extern value fexl_string_double(value);
extern value fexl_string_at(value);
extern value fexl_string_common(value);
