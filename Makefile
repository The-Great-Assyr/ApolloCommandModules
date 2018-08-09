SLUG = ApolloCommandModules
VERSION = 0.6.0
RACK_DIR ?=

CXXFLAGS += -I$(RACK_DIR)/include
FLAGS +=
LDFLAGS +=

DISTRIBUTABLES += $(wildcard LICENSE*) res
SOURCES += $(wildcard src/*.cpp)

include $(RACK_DIR)/plugin.mk
