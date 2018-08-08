SLUG = ApolloCommandModules
VERSION = 0.6.2

CXXFLAGS +=
FLAGS +=
LDFLAGS +=

DISTRIBUTABLES += $(wildcard LICENSE*) res
RACK_DIR ?= ../..
SOURCES += $(wildcard src/*.cpp)

include $(RACK_DIR)/plugin.mk
