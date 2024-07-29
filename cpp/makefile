CXXFLAGS += -g
CXXFLAGS += -std=c++20
TARGET = main

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

all: $(TARGET)

-include $(wildcard *.d)
all: $(DEPS)

$(TARGET): $(OBJS)
	$(CXX) $^ $(LFLAGS) -o $@

%.d: %.cpp
	$(CXX) -M $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

compile_commands.json:
	compiledb make -Bn

