default: ncbi-json ncbi-jwt ncbi-oauth-test

BINDIR = $(CURDIR)/bin
LIBDIR = $(CURDIR)/lib
OBJDIR = $(CURDIR)/obj

$(BINDIR) $(LIBDIR) $(OBJDIR):
	mkdir -p $@

# only for Linux and MacOS
OBJX = o
LOBX = pic.o

# tell make to forget some of its built-in rules
.SUFFIXES:

# C++ compiler to use
GPP ?= g++ -std=c++11

# rule to build object files from source
$(OBJDIR)/%.$(LOBX): ncbi-json/%.cpp
	$(GPP) $(CFLAGS) -g -c $< -o $@ -Incbi-json -Iinc -fPIC -MD -Wall

$(OBJDIR)/%.$(LOBX): ncbi-jwt/%.cpp
	$(GPP) $(CFLAGS) -g -c $< -o $@ -Incbi-jwt -Iinc -fPIC -MD -Wall

$(OBJDIR)/%.$(OBJX): ncbi-oauth-test/%.cpp
	$(GPP) $(CFLAGS) -g -c $< -o $@ -Incbi-oauth-test -Iinc -Igoogletest/googletest/include -MD -Wall
$(OBJDIR)/%.$(OBJX): googletest/googletest/src/%.cc
	$(GPP) $(CFLAGS) -g -c $< -o $@ -Incbi-oauth-test -Iinc -Igoogletest/googletest -Igoogletest/googletest/include -MD

# include dependencies
include $(wildcard $(OBJDIR)/*.d)

## ncbi-json
LIBJSONSRC =       \
	parser         \
	json-object    \
	json-array     \
	json-wrapper   \
	json-primitive \
	json-value     \
	json-exception

LIBJSONOBJ = \
	$(addprefix $(OBJDIR)/,$(addsuffix .$(LOBX),$(LIBJSONSRC)))

ncbi-json: $(LIBDIR) $(LIBDIR)/libncbi-json.a

$(LIBDIR)/libncbi-json.a: $(OBJDIR) $(LIBJSONOBJ) $(MAKEFILE)
	ar -rc $@ $(LIBJSONOBJ)

## ncbi-jwt
LIBJWTSRC =     \
	jwt         \
	base64

LIBJWTOBJ = \
	$(addprefix $(OBJDIR)/,$(addsuffix .$(LOBX),$(LIBJWTSRC)))

ncbi-jwt: $(LIBDIR) $(LIBDIR)/libncbi-jwt.a

$(LIBDIR)/libncbi-jwt.a: $(OBJDIR) $(LIBJWTOBJ) $(MAKEFILE)
	ar -rc $@ $(LIBJWTOBJ)

## ncbi-oauth-test
OAUTHTESTSRC =    \
	main          \
	gtest-all     \
	ncbi-json-ut  \
	ncbi-jwt-ut

OAUTHTESTOBJ = \
	$(addprefix $(OBJDIR)/,$(addsuffix .$(OBJX),$(OAUTHTESTSRC)))

OAUTHTESTLIB =  \
	-L$(LIBDIR) \
	-lncbi-jwt  \
	-lncbi-json \
	-lpthread

ncbi-oauth-test: $(BINDIR) $(BINDIR)/ncbi-oauth-test

$(BINDIR)/ncbi-oauth-test: $(OBJDIR) $(OAUTHTESTOBJ) $(MAKEFILE)
	$(GPP) -g -o $@ $(OAUTHTESTOBJ) $(OAUTHTESTLIB)

clean:
	rm -rf $(OBJDIR) $(LIBDIR) $(BINDIR)

.PHONY: default
