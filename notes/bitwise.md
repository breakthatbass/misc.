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
- `1 + 64` = `65`  
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


## bitwise operators & bitmasks

- `&` and
- `|` or
- `~` not
- `^` xor
- `<<` shift left
- `>>` shift right
#
- `&` : extracts data
- `|` : sets data
- `^` : toggles data
- `~` : 'flips' data
#
bit masks are an abstract way to deal with specific bytes in a binary.  
let's say we have a binary, `01011101`, or `187`, and we want to deal with the third bit in from the left.  
our mask would look like this: `00100000` we have a 1 in the place of the bit we care about.  
we can now use the mask to execute any of the operators above on it.  
```
    01011101
&   00010000
--------------
    00010000
```
or
``` C
int n = bin & mask;
```
and if we're looking at seperate bits within a bitfield, we would move that n over to right the amount of places it would need to go to trim the trailing zeros.
```C
n = n >> 3;
```
This is never done this way though.  
   
     
let's say we want to clear the bit, which is to say, leave the bits alone except for the one bit we care about.   

we could do this:
``` C
int n = bin & ~(mask);
```
this the mask, inverts it with `~` and ANDs in to the binary. it would end up looking like this after the inversion:
```
bin:        01011101
mask:     & 11101111
         --------------
            01001101
```
the end product is the same as the original except for the one bit that got cleared.  
in the real world, it would look like this:
```C
int y = 1;  // 1 because we're only dealing with one bit in the mask
bin &= ~(y << 4);
```
we shift to the left 4 spots because `1` is the equivelent of `00000001`.
we could also just do:
```C
int y = 16;  // same as 00010000
bin &= ~(y);
```
### toggling bits
we'll be using `^` to toggle bits. aka turn on or off the bits.  
```C
bin = 0b10111011;  // 187
mask = 0b00100000;
// same as before

int n = bin ^ mask;

// or the more abstract way
int y = 1;
bin ^= (y << 5); // produces 155

// and we can switch it back the same way
bin ^= (y << 5); // back to 187
```

## bitfields

``` C
union {
    struct bitfield {
        char unused: 1;
        char sw2: 1;
        char sw1: 1;
        char state: 2;
        char value: 3;
    }
    char reg;
};
```

above is an example of a bitfield for an 8-bit binary. 
if you load the `struct` with a binary, it will store the appropriate parts in those variables.  
let's say we have `10111011` and loaded it into the struct.  
`unsued = 1` the fisrt bin  
`sw2 = 0` the second bin  
`sw1 = 1` the third bin  
`state = 1 & 0` the fourth and fifth bins  
`value = 0 & 1 & 1` the last three  

the `union` is for the `reg` variable. if we set that, it sets all the bits.  
in the case of, say an NES emulator where we want to reset, we can set `reg = 0x00` which will set every variable in the struct to `0`.