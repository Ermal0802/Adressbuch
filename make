APP=addressbook
SOURCES=$(wildcard ./*.cpp)

$(APP): $(SOURCES)
        g++ -o $(APP) $(SOURCES)

test: $(APP)
        ./$(APP)
