BUILD?=./build
BIN=discord-bot

all:
	cmake -S . -B $(BUILD) -G Ninja
	ninja -C $(BUILD)

run: all
	$(BUILD)/$(BIN)

clean:
	$(RM) -r $(BUILD)
