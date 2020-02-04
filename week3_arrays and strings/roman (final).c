/*
Feedback from nj19182: Good work. Only a few nitpicky things: [INDENT] and [BRACE]:
you put everything in one case on the same line.
This is against the house style rules although I personally find it easy to read.
Other than that I really like that you restrain the number range to less than
3999 and reflect if the input letter isn't a roman numeral letter.
Good comments as well. Overall 65%.

Feedback from ma19230: nice coding - no house-style issues,
having many testing for different situations, no error. Overall:80%

Feedback from rr16973: I like that you defined all the values beforehand as
it made the code really clear to read and understand.
I also thought it was good that you included an error message
in-case the range or the characters did not fit within the parameters of the code
Well done. Overall:60-65%
*/

/*This program could reads a roman numeral and
  outputs the corresponding valid arabic integer*/
#include <stdio.h>
#define NDEBUG
#include <assert.h>
/* The value of different characters */
#define M_VALUE 1000
#define D_VALUE 500
#define C_VALUE 100
#define L_VALUE 50
#define X_VALUE 10
#define V_VALUE 5
#define I_VALUE 1
/* roman numberal range between 1-3999 */
#define ROMAN_MAX 3999

int romanToArabic(char roman[]);
void test(void);

int main(int argc,char **argv)
{
  test();
  if (argc==2) {
    printf("The roman numeral %s is equal to %d\n",\
    argv[1],romanToArabic(argv[1]));
  }
  else {
    printf("ERROR:Incorrect usage, try e.g. %s XXI\n",argv[0]);
  }
  return 0;
}

/* testing, input characters, numbers or lower-character will be error */
void test(void)
{
  assert(romanToArabic("MCMXCIX")==1999);
  assert(romanToArabic("MCMLXVII")==1967);
  assert(romanToArabic("MCDXCI")==1491);
  assert(romanToArabic("MMMM")==-1);
  assert(romanToArabic("Mi")==-1);
  assert(romanToArabic("dankd")==-1);
  assert(romanToArabic("321d3")==-1);
}

/* read a roman numeral and output the corresponding valid arabic integer */
int romanToArabic(char roman[])
{
  /* if put any other characters, flag will be 1 */
  int i,numeral=0,flag=0;
  for (i=0;roman[i];i++) {
    switch (roman[i])
    {
      case 'M':
        numeral += M_VALUE;
        break;

      case 'D':
        numeral += D_VALUE;
        break;

      case 'C':
        if (roman[i+1]=='M'||roman[i+1]=='D') {
          numeral -= C_VALUE;
        }
        else {
          numeral += C_VALUE;
        }
        break;

      case 'L':
        numeral += L_VALUE;
        break;

      case 'X':
        if (roman[i+1]=='C'||roman[i+1]=='L') {
          numeral -= X_VALUE;
        }
        else {
          numeral += X_VALUE;
        }
        break;

      case 'V':
        numeral += V_VALUE;
        break;

      case 'I':
        if (roman[i+1]=='X'||roman[i+1]=='V') {
          numeral -= I_VALUE;
        }
        else {
          numeral += I_VALUE;
        }
        break;

      default:
        flag=1;
    }
  }
  /* check the range and characters */
  if (flag==1 || numeral > ROMAN_MAX){
    printf("ERROR:Incorrect format or number! Result will be -1.\n");
    return -1;
  }
  else
    return numeral;
}
