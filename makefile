SOURCES = $(wildcard *.cpp)
APP = addressbook

ALL: $(APP)
	@echo Done

$(APP): $(SOURCES)
	g++ -o $(APP) $(SOURCES)

test: $(APP)
	./$(APP)