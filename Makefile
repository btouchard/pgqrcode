CFLAGS += -std=c99 -O

MODULE_big   = pgqrcode-0.0.1
OBJS 		 = src/pgqrcode.o src/qrcodegen.o
EXTENSION    = pgqrcode
DATA         = $(wildcard sql/pgqrcode--*.sql)

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)