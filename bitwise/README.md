# bitwise basics & overview

thanks to [javidx9](https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA) with his NES emulator video which [part 1](https://www.youtube.com/watch?v=F8kx56OZQhg&t=310s) spends a lot of time on this stuff and is probably the clearest lesson on the topic. this is primarily where i took these notes from.

## 3 ways to represent numbers

3 types of bases: base 10, base 2 (binary), & base 16 (hexidecimal)

### number:  
`dec`: 65   
`bin`: `010000010`

if we represent this number in base 10 (decimal) as we normally use numbers in real life 

**base 10**
|nth place|7     |6     |5     |4     |3     |2     |1     |0     |
|---------|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|number   |0     |0     |0     |0     |0     |0     |6     |5     |
|mult     |0x10^7|0x10^6|0x10^5|0x10^4|0x10^3|0x10^2|6x10^1|5x10^0|  


**results**: 
- `0x10^n` will always be zero which means there are no numbers in that place.  
- `6x10^1 = 60` since that means there is a 6 in the tens place.  
- `5x10^0 = 5` since that's for the ones place.  
- `60 + 5 = 65`
#
**base 2** (binary)
|nth place|7     |6     |5     |4     |3     |2     |1     |0     |
|---------|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|bin      |0     |1     |0     |0     |0     |0     |0     |1     |
|mult     |0x2^7 |1x2^6 |0x2^5 |0x2^4 |0x2^3 |0x2^2 |0x2^1 |1x2^0 |  

**result**: 
- `1x2^0` = `1` (decimal)  
- `1x2^6` = `64` (decimal)  
`- 1 + 64` = `65`  
- this is an 8-bit binary number which means there are 8 places to store a number. 8-bits is equal to 1-byte -> the size of a `char` on most systems.  
- in each place, you multiply the number there by `2^n`. then you sum the numbers. 
- the `0`s will always multiply to `0`. and the `1`s will be a number.
#
Table to represent what the ones are in each place with bin num `11111111`:
|nth place|7     |6     |5     |4     |3     |2     |1     |0     |
|---------|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
|number   |128   |64    |32    |16    |8     |4     |2     |1     |
|mult     |1x2^7 |1x2^6 |1x2^5 |1x2^4 |1x2^3 |1x2^2 |1x2^1 |1x2^0 |  

**results**
- `11111111` in binary would be `128` + `64` + `32` + `16` + `8` + `4` + `2` + - `1` which equals `255`.  
- `255` is the highest number an 8-bit number can go.
#
## hexidecimal notation

there are only 16 different symbols for hexidecimal and no double digits.  
symbols: `0123456789ABCDEF`  
which are the numbers 0 - 15.  
`0` - `9` represent the numbers `0` - `9` as they are.  
```
A 10
B 11
C 12
D 13
E 14
F 15
```


## bitwise operators

- `&` and
- `|` or
- `~` not
- `^` xor
- `<<` shift left
- `>>` shift right