# MD5-miner
very very rough stages
testing implementation of an accelarator on HPS+FPGA (DE-1 SOC)
based on libraries provided by those below

goal is to measure improvement in hashrate of MD5 from ARMv7 core to a branched (possibly parallel) accelerator

## known issues:
### software
+ nonce incrementation
+ need to clean up functions & values
    - converting nonce, data, and previous hash pointers to the inside of the uint8_t input_array
    - clarify which files will do what
+ test on ARMv7 -> QEMU?

### acceleration
+ look at IO of MD5 accelerator
    - how many "cores" can fit on the CycloneV
    - how to connect to HPS (FSM on FPGA to control the tasks)
+ linux set up on DE-1

## Credit

@Zunawe Bryce Wilson - C implementation of MD5 algorithm

## hypothetical blockchain
in order:  
128 bits    ->  previous hash  
340 bits    ->  data  
64 bits     ->  nonce  

total: 512 bits (fits perfectly inside the MD5 packet size)