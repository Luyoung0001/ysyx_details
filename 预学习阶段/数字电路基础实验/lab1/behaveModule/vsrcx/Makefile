simu:
	@verilator --cc mux21c.v --exe main.cpp --trace

run: simu
	@bear -- make -C obj_dir -f Vmux21c.mk && \
	./obj_dir/Vmux21c

clean:
	@rm -rf obj_dir