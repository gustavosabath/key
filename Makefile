include Makefile.inc

HEADER = key.h
INPUT = key.c
OBJ = key

install: $(OBJ)

$(OBJ): $(INPUT) $(HEADER).inc
	@sed 's|@ENABLEPATH|$(ENABLE_PATH)|g; s|@DISABLEPATH|$(DISABLE_PATH)|g' $(HEADER).inc > $(HEADER)
	@gcc $(INPUT) -o $(OBJ)
	@sudo cp $(OBJ) /usr/bin

clear:
	@rm -f $(OBJ)
	@rm -f $(HEADER)
	@sudo rm -f /usr/bin/$(OBJ)