#define inverse(a)\
(0 | (( a & 0x000000ff ) << 24 )\
|    (( a & 0x0000ff00 ) << 8  )\
|    (( a & 0x00ff0000 ) >> 8  )\
|    (( a >> 24 ) & 0x000000ff ) )
