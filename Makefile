BUILD?=./build
BIN=discord-bot
CXX?=g++
SRC=./src

all: dynamic_linked

static_linked:
	cmake -S . -B $(BUILD) -G Ninja
	ninja -C $(BUILD)

run: all
	$(BUILD)/$(BIN)

dynamic_linked:
	mkdir -p $(BUILD)
	$(CXX) $(SRC)/*.cpp -ldpp -lfmt -lsqlite3 -Iinclude -O3 -o $(BUILD)/$(BIN)

clean:
	$(RM) -r $(BUILD)
