CFLAGS += -std=c99 -O

MODULE_big   = pgqrcode-1.0.0
OBJS 		 = src/pgqrcode.o src/qrcodegen.o
EXTENSION    = pgqrcode
DATA         = $(wildcard sql/pgqrcode--1.0.0.sql)

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)