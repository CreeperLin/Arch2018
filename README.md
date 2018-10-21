# Arch2018

Project resources for System(I) 2018 Fall

## Project Structure

### Adder Assignment

- sim: used for testing adder in simulation
- src: template & support files for adder assignment
- ctrl: controller for testing adder on FPGA via UART

#### Simulation

Using Vivado

1. Create a RTL project in Vivado
2. Put 'adder.v' into 'Sources'
3. Put 'test_adder.v' into 'Simulation Sources'
4. Run Behavioral Simulation
5. Make sure to run at least 100 steps during the simulation (usually 100ns)
6. You can see the results in 'Tcl console'

Or using iverilog:

    iverilog test_adder.v
    vvp a.out

#### FPGA testing

In top directory, clone the serial library and build

    git submodule update --init
    cd serial
    make
    make install

Dependencies see [wjwwood/serial](https://github.com/wjwwood/serial)

In 'ctrl' folder, build the controller

    ./build.sh

Run the controller (may require superuser privilege)

    ./run.sh uart-port

the UART port should look like:

on Linux: /dev/ttyUSB1

on WSL: /dev/ttyS4

on Windows: COM3 (not tested)

### RISC-V ISA Assignment

(not implemented)
