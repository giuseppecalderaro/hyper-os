%.o: %.S
	@echo CC  $<
	@$(CC) $(CFLAGS) -DASM -c -o $@ $<

%.o: %.c
	@echo CC  $<
	@$(CC) $(CFLAGS) -c -o $@ $<
