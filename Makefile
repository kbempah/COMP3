cc := g++
cppflags := -g -Wall -std=c++11
target := prog

.PHONY : all
all : $(target)

# path to source files
srcdir := .

# path to directories for .o and .d files
objdir := .obj
depdir := $(objdir)/depfiles

srcs := $(wildcard $(srcdir)/*.cpp) # generate source files
objs := $(srcs:%.cpp=$(objdir)/%.o) # generate object files from source files
depfiles = $(srcs:%.cpp=$(depdir)/%.d) # generate dependency files from source files

depflags = -MMD -MT $@ -MP -MF $(depdir)/$*.td	# dependency flags. this is where the magic happens
compile.c := $(cc) $(cppflags) $(depflags) -c # compile options and flags
postcompile := mv -f $(depdir)/$*.td $(depdir)/$*.d && touch # this step can be omitted but used to harden makefile

output.opt := -o # specify output options

# generate binary
$(target) : $(objs)
	$(cc) $^ $(output.opt) $@

# target to compile all .cpp files, generating .d files in the process
$(objdir)/%.o : %.cpp $(depdir)/%.d | $(depdir)
	$(compile.c) $< $(output.opt) $@
	$(postcompile) $@

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