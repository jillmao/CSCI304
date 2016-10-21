/* 
 * CS:APP Data Lab 
 * 
 * <Jill Mao, jjmao, 930891998>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
  //return 2;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
/*
 * Shift x left 31 bits so that the least bit is the only bit remaining.
 * Then shift x right 31 bits so it is either all 0's or all 1's
 */
  return (x << 31) >> 31;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
/*
 * Shift n left 3 bits, so that n is multiplied by 8.
 * Then shift x right n bits so that the bytes needed to be extracted are farthest right.
 * Use &0xff to extract the needed bytes.
 */
  return (x >> (n << 3)) & 0xff;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
/*
 * Use x^y: if x and y are equal, only 0's will remain.
 * Use the ! operator: if x^y is 0x0, then 1 will be returned. 0 will be returned otherwise.
 */
  return !(x ^ y);
}
/* 
 * bitMask - Generate a mask consisting of all 1's 
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
/*
 * Divide the mask into a low part and a high part. Flip 0 so that it is all ones.
 * For the high, shift the flipped 0 left (highbit + 1) so that the variable high is 0...highbit with 1's at the left. 
 * If highbit is 5, then int high = 1110 0000.
 * For the low, shift the flipped 0 left (lowbit) so that the variable low is 0...lowbit - 1 with 1's at the left.
 * If lowbit is 3, then int low = 1111 1100.
 * Use (high ^ low) to extract the 1's in between highbit and lowbit. 
 * Apply (&low) last so that if lowbit is higher than highbit, 0 will be returned.
 */
    int high = (~0 << (highbit)) << 1;
    int low = ~0 << lowbit;
  return ((high ^ low) & low);
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
/*
 * Divide x into four variables, one for each byte by shifting x so that the soon to be extracted bytes are in the desired position.
 * Then use the appropriate form of 0xff to extract the bytes at the correct position.
 * Place all variables next to each other with the | operator to get the intended effect of reversed bytes.
 */    
    int byte0 = (x >> 24) & 0x000000ff;
    int byte1 = (x >> 8) & 0x0000ff00;
    int byte2 = (x << 8) & 0x00ff0000;
    int byte3 = x << 24;
  return (byte0 | byte1 | byte2 | byte3);

}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
/* 
 * Any form of (~x^negative) will not work because 0x80000000 is also the same as its negative.
 * 0 is different because both 0 and -0 have the same positive sign.
 * 0x80000000 and -(0x80000000) have the same negative sign.
 * To take advantage of this, (x|negative) is executed and only 0 will have 0 as its msb,
 * every other number will have 1.
 * (x|negative) is shifted to the right by 31 to get either 0 or -1.
 * If 1 is added, only 0 will have 1 as its final result.
 * Every other number will have 0 as its final result because (x|negative) will surely return -1.
 */
    int negative = ~x + 1;
    return ((x|negative)>>31)+1;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
    /* 
   * To find negative x, all of the bits must be flipped and 0x1 is added.
   * After adding 0x1, 1 will end up in the position of the least bit in x.
   * The bits to the left remain flipped and the bits to the right (if any) are 0.
   * If (x& -x) is used, only the least bit in x will be caught in the mask because the rest have been flipped or are 0.
   */
    int negative = ~x + 1;
  return x & negative;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
//Return -1 in hex.
  return 0xffffffff;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
//Return largest possible hex.
  return 0x7fffffff;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    /*I found it to be impossible to isolate the positive and negative cases and use the &,^, or | operators to account for both cases when returning,
     * because if one case is true the other is always false. This leads to always false(&), always true(^), or a contradiction(|). 
     *The only binary operator left is +, so to use this, one case has to always equal 0, and the other can be anything.
     The sign is first extracted, and then another variable is made to hold the opposite sign. One of these is 0x0 and the other is 0xf.
     The largest positive number n bits can hold starts with 0 and has (n-1) number of 1's following it.
     So for the positive case, when x>>(n-1), there are always left over 1's on the left side.
     To get the smallest negative number, the largest positive number is flipped so that 1 is the first number and (n-1) number of 0's follow it
     For the negative case, when ~x>>(n-1), there are always left over 1's on the left side.
     We do not know if x is positive or negative, but if we try (~x&sign) and (x&other_sign), one of these will surely be 0x0,
     and the other will be either (positive x)>>(n-1) or (~(negative x))>>(n-1)*/
    int sign = x>>31;
    int other_sign = ~sign;
    int n_minus1 = n + ~0;

    return !(((~x&sign)+(x&other_sign))>>n_minus1);
}
/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
   /*Paying attention only to signs:
    * With overflow: 1)x=positive, y=positive, added=negative
    *                2)x=negative, y=negative, added=positive
    * No overflow:   1)x=positive, y=positive, added=positive
    *                2)x=negative, y=negative, added=negative
    *                3)x=negative, y=positive, added=doesn't matter
    *                4)x=positive, y=negative, added=doesn't matter
    * 
    *When (x+y) is executed, the last bit will equal 1 only if x and y are different signs.
    *(x+y)<<31 will return 1 and detect the case when x and y are different signs.
    * Now there must be a way to return 1 when x and y are the same signs.
    * If (~added+y) is executed, only the cases with no overflow will have 1 as the last bit.
    * (~added+y)<<31 will return 1 when x and y are the same signs and there is no overflow.
    * ((x+y)<<31)|((~added+y)<<31) will detect all of the cases for no overflow.
    * !! is added in front, just in case there are other bits remaining after the previous operation is performed,
    * only the last bit needs to be returned.
    */
    int added = (x + y) >> 31;
    x = x >> 31;
    y = y >> 31;
    return !!(((x+y)<<31)|((~added+y)<<31));
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  //Value is 1 if x > y, assuming signs are not involved in the considerations.
 // int value = !((x + ~y) >> 31);
  //The sign bits of x and y need to be isolated to augment the above definition
  //of the operation. If x is positive but y is negative, 1 will be returned
  //regardless of what the above value is. Otherwise the value will be returned
  //as long as x isn't negative concurrently with y being positive.
  int msbx = (x>>31);
  int msby = (y>>31);
  int if_neg_overflow = !((x+y)>>31);
  int overflow = 1<<(32 + (~if_negative_overflow+1));
  //int same = !(x^y);
  int msb_add = msbx + msby;
  int sign = !(msb_add);
//return (!x & y) | (value & (!x | y));
  //return !(((x+(~y+1)+~0)+sign)+overflow);
  return!(x+(~y+1));   
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
/* 
 * Shift x 31 bits to the right so that its leftmost bit is farthest right.
 * Use &1 to extract the rightmost bit. 
 * int x is signed by default so it will return 1 if negative and 0 otherwise.
 */
    return (x>>31) & 1;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
  //int multiply_Five = (x << 2) + x;
  
  // if multFive is negative, add 2^3 - 1 = 7 before right shift
  //int addNum = 7 & (multFive >> 31);
  //int divEight = (multFive + addNum) >> 3;
  
 //return divEight;
  return 2;
}
/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  return 2;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
