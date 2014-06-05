if ENABLE_GLIB

lib_LTLIBRARIES += libbson-glib-1.0.la

libbson_glib_1_0_la_SOURCES = \
	src/bindings/glib/bson-glib.c \
	src/bindings/glib/bson-glib.h

libbson_glib_1_0_la_LIBADD = \
	libbson-1.0.la \
	$(GLIB_LIBS)

libbson_glib_1_0_la_CFLAGS = \
	-I$(top_srcdir)/src/bson \
	-I$(top_builddir)/src/bson \
	$(OPTIMIZE_CFLAGS) \
	$(MAINTAINER_CFLAGS) \
	$(GLIB_CFLAGS)

include $(INTROSPECTION_MAKEFILE)

INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(top_srcdir)/src/bson --add-include-path=$(top_builddir)/src/bson --add-include-path=$(top_srcdir)/src/bindings/glib --warn-all
INTROSPECTION_COMPILER_ARGS = --includedir=$(top_srcdir)/src/bindings/glib

Bson-1.0.gir: libbson-glib-1.0.la

Bson_1_0_gir_INCLUDES = GObject-2.0
Bson_1_0_gir_CFLAGS = \
	-DBSON_COMPILATION \
	-DBSON_DISABLE_ASSERT \
	-I$(top_srcdir)/src/bson \
	-I$(top_builddir)/src/bson \
	-include stdint.h \
	-include stdbool.h
Bson_1_0_gir_LIBS = libbson-glib-1.0.la
Bson_1_0_gir_FILES = \
	$(libbson_glib_1_0_la_SOURCES) \
	src/bson/bson.h \
	src/bson/bson-types.h \
	src/bson/bson-iter.h \
	src/bson/bson-reader.h \
	src/bson/bson-writer.h
Bson_1_0_gir_EXPORT_PACKAGES = libbson-1.0
Bson_1_0_gir_SCANNERFLAGS = --c-include="bson-glib.h" --namespace=Bson --symbol-prefix=bson_ --identifier-prefix=bson_
INTROSPECTION_GIRS += Bson-1.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)

endif
