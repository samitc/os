CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix ,$(notdir $(CPP_FILES:.cpp=.o)))
CC_FLAGS := -ffreestanding

all: makeInt

makeInt: $(OBJ_FILES)

$(OBJ_FILES): $(CPP_FILES)
	$(CCompiler) $(CC_arg) $(CC_FLAGS) -c $< -o $@

clean:
