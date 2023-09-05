cc := g++
cppflags := -g -Wall -std=c++11
target := prog

all : $(target)

# directories for .o and .d files
objdir := .obj
depdir := $(objdir)/depfiles

# all source, object, and dependency files
srcs := $(wildcard *.cpp)
objs := $(srcs:%.cpp=$(objdir)/%.o)
depfiles = $(srcs:%.cpp=$(depdir)/%.d)

depflags = -MMD -MT $@ -MP -MF $(depdir)/$*.td
# postcompile = mv -f $(depdir)/$*.td $(depdir)/$*.d && touch $@

# generate binary
$(target) : $(objs)
	$(cc) -o $@ $^

# target to compile all .cpp files, generating .d files in the process
$(objdir)/%.o : %.cpp $(depdir)/%.d | $(depdir)
	$(cc) $(cppflags) $(depflags) -o $@ -c $<
	mv -f $(depdir)/$*.td $(depdir)/$*.d && touch $@

# empty explicit target for handling missing .d files
$(depfiles) :

# target to create object and dependency directories if they don't exist
$(depdir):
	@mkdir -p $@

.PHONY : clean
clean :
	rm -rf $(target) $(objs) $(depfiles) $(depdir)/ $(objdir)/

# include all the dependency files
include $(wildcard $(depfiles))

# Link to article explaining the concepts used here -> https://make.mad-scientist.net/papers/advanced-auto-dependency-generation/