SIMU = verilator --cc reg1bit.v --exe main.cpp --trace

run: simu
	@make -C obj_dir -f Vreg1bit.mk && \
	./obj_dir/Vreg1bit

simu:
	@$(SIMU)

clean:
	@rm -rf obj_dir
.PHONY: clean simu run
