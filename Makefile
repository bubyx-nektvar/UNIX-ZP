.PHONY: clean All

All:
	@echo "----------Building project:[ UNIX-ZP - Debug ]----------"
	@"$(MAKE)" -f  "UNIX-ZP.mk"
clean:
	@echo "----------Cleaning project:[ UNIX-ZP - Debug ]----------"
	@"$(MAKE)" -f  "UNIX-ZP.mk" clean
