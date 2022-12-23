# MD5-miner
very very rough stages
testing implementation of an accelarator on HPS+FPGA (DE-1 SOC)
based on libraries provided by those below

goal is to measure improvement in hashrate of MD5 from ARMv7 core to a branched (possibly parallel) accelerator


## Credit

@Zunawe Bryce Wilson - C implementation of MD5 algorithm

## hypothetical blockchain
in order:
128 bits - previous hash
340 bits - data
64 bits - nonce

total: 512 bits (fits perfectly inside the MD5 packet size)