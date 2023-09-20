cc := clang++
cppflags := -g -Wall -std=c++17
target := prog

# path to directories for .o and .d files
objdir := obj
depdir := $(objdir)/dep

srcs := main.cpp # generate source files from current directory
objs := $(srcs:%.cpp=$(objdir)/%.o) # generate object files from source files
deps := $(srcs:%.cpp=$(depdir)/%.d) # generate dependency files from source files

# postcompile := mv -f $(depdir)/$*.td $(depdir)/$*.d && touch # this step can be omitted but used to harden makefile

.PHONY : all
all : $(target)

# generate binary
$(target) : $(objs)
	$(cc) $^ -o $@

# target to compile all .cpp files, generating .d files in the process
$(objdir)/%.o : %.cpp $(depdir)/%.d | $(depdir)
	$(cc) -MMD -MT $@ -MP -MF $(depdir)/$*.d -c $(cppflags) $< -o $@

# empty explicit target for handling missing .d files
$(deps) :

# target to create object and dependency directories if they don't exist
$(depdir):
	@mkdir -p $@

.PHONY : clean
clean :
	-rm -rf $(target) $(objdir)

# include all the dependency files
include $(wildcard $(deps))

# Link to article explaining the concepts used here -> https://make.mad-scientist.net/papers/advanced-auto-dependency-generation/
# Credits to Jeremiah Knol for visual demonstration through video.