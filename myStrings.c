#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//strlen [ int strlen( char * ) ]

int myLen(char *x) {

  int ret = 0;
  while(*x) {
    *x ++;
    ret ++;
  }
  return ret;
}

//strcpy/strncpy (choose one)  [ char * strcpy( char *dest, char *source )  char * strncpy( char *dest, char *source, int n)  ]

char * myStrcpy(char *dest, char *str) {

  char *i = dest;
  while(*(str - 1) || *str) {
    *i = *str;
    *i++;
    *str++;
  }
  return dest;
}

char * myStrncpy(char *dest, char *str, int n) {
  char *i = dest;
  while(n && *str) {
    *i = *str;
    *i++;
    *str++;
    n--;
  }
  return dest;
}

//strcat/strncat (choose one)  [ char * strcat( char *dest, char *source )  char * strncat( char *dest, char *source, int n)  ]

char * myStrcat(char *dest, char *str) {
  char *i = (dest + myLen(dest));
  while(*(str-1) || *str) {
    *i = *str;
    *str++;
    *i++;
  }
  return dest;
}

char * myStrncat(char *dest, char *str, int n) {
  char *i = (dest + myLen(dest));
  while(n && *str) {
    *i = *str;
    *str++;
    *i++;
    n--;
  }
  *i = '\0';
  return dest;
}


//strcmp  [ int strcmp( char *s1, char *s2 ) ]

int myStrcmp(char *s1, char *s2) {
  while(*s1 != '\0') {
    if (*s2 == '\0') {
      return 1;
    }
    else if (*s1 > *s2) {
      return 1;
    }
    else if (*s2 < *s1) {
      return -1;
    }
    *s1++;
    *s2++;
  }
  if (*s2 != '\0') {
    return -1;
  }
  else {
    return 0;
  }
}

//strchr  [ char * strchr( char *s, char c ) ]

char * myStrchr(char *s, char c) {
  while(*s) {
    if (*s == c) {
      return s;
    }
    *s++;
  }
  return NULL;
}

int main() {

  char s1[] = "Crookshanks";
  char s2[] = "Hedwig";
  char s3[] = "Scabbers";
  char s4[] = " owl";

  printf("\nBefore applying fxns:\ns1 = %s , length = %lu\ns2 = %s , length = %lu\ns3 = %s , length = %lu\n\n", s1, strlen(s1), s2, strlen(s2), s3, strlen(s3));

  printf("Applying myLen:\ns1 = %s , length = %d\ns2 = %s , length = %d\ns3 = %s , length = %d\n", s1, myLen(s1), s2, myLen(s2), s3, myLen(s3));

  printf("\nApplying myStrcpy:\nHedwig[s2] copied onto Crookshanks[s1]:%s", myStrcpy(s1, s2));
  printf("\nNew s1:%s\n", s1);

  printf("\nApplying myStrncpy:\n\"Crookshanks\" copied onto s2, but within the memory allocated for s2:%s\n", myStrncpy(s2, "Crookshanks", sizeof(s2)));
  printf("New s2:%s\n", s2);

  printf("\nApplying myStrcat:\n\" owl\" cated onto Hedwig[s1]:%s\n", myStrcat(s1, s4));
  printf("Length of s1: %d", myLen(s1));
  printf("\nSize of s1: %lu", sizeof(s1));
  printf("\nApplying myStrncat:\nScabbers[s3] cated onto Hedwig[s1]:%s\n", myStrncat(s1, s3, sizeof(s1) - myLen(s1)));

  printf("\nS1:%s, %s", s2, "Dog");
  printf("\nApplying myStrcmp:\ns1 compared to Dog: %d\n", myStrcmp(s2, "Dog"));
  printf("Applying built in function: %d\n", strcmp(s2, "Dog"));//Does this not take into account length? I'm getting -#, but I thought it should be +#

  printf("\ns3: %s", s3);
  printf("\nApplying myStrchr: %s", myStrchr(s3, 'r'));
  printf("\nApplying strchr: %s\n", strchr(s3,'r'));

  return 0;
}
