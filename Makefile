ObjSuf        = o
SrcSuf        = cc
ExeSuf        = 
DllSuf        = so
OutPutOpt     = -o
HeadSuf       = h

# Linux with egcs
DEFINES       = -DNO_ORCA_CLASSES
CXX           = g++
CXXFLAGS	= -O -Wall -fPIC $(DEFINES)
LD		= g++
LDFLAGS		= -g -O -Wall -fPIC
SOFLAGS		= -shared

#------------------------------------------------------------------------------

SOURCES		= $(wildcard *.cc  tinyxml/*.cc)
HEADERS		= $(wildcard *.h tinyxml/*.h)
OBJECTS		= $(SOURCES:.$(SrcSuf)=.$(ObjSuf))
DEPENDS		= $(SOURCES:.$(SrcSuf)=.d)
SOBJECTS	= $(SOURCES:.$(SrcSuf)=.$(DllSuf))

SOURCES_TINYXML = $(wildcard tinyxml/*.cc)
OBJECTS_TINYXML = $(SOURCES_TINYXML:.$(SrcSuf)=.$(ObjSuf))

all: $(OBJECTS) buildLatex rssToDataLatex

.SUFFIXES: .$(SrcSuf) .C .o .so

buildLatex: buildLatex.o $(OBJECTS_TINYXML)
	g++ -o $@ $+

rssToDataLatex: rssToDataLatex.o $(OBJECTS_TINYXML)
	g++ -o $@ $+

	
