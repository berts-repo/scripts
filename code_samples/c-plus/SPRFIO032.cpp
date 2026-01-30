#include <stdio.h>
#include <string.h>
#include <strings.h>

static int isReservedName(const char *path);
static int casecmp(const char *a, const char *b);

// Program Name: SPRFIO032.cpp
// Author: GT
// This program shows how to check devices that are not files

int main(void) {
	char userPath[] = "LPT1";
	if (isReservedName(userPath)) {
		printf("[%s] is a reserved path name\n",userPath);
	}
	else {
		printf("[%s] is not a reserved path name\n",userPath);
	}

	return 0;
}

static int casecmp(const char *a, const char *b) {
#ifdef _WIN32
	return _stricmp(a, b);
#else
	return strcasecmp(a, b);
#endif
}

static int isReservedName(const char *path) {
  /* This list of reserved names comes from MSDN */
  static const char *reserved[] = {
    "nul", "con", "prn", "aux", "com1", "com2", "com3",
    "com4", "com5", "com6", "com7", "com8", "com9",
    "lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6",
    "lpt7", "lpt8", "lpt9"
  };
  int sizeOfList = sizeof(reserved) / sizeof(reserved[0]);
  int returnValue  = 0 ;   //0 -> false 1-> true

/*
 * First, check to see if this is a device namespace, which
 * always starts with \\.\, because device namespaces are not
 * valid file paths.
 */

  if (!path || 0 == strncmp(path, "\\\\.\\", 4)) {
    return 1;
  }

  /* Compare against the list of ancient reserved names */
  for (int i = 0; returnValue != 1 && i < sizeOfList; i++) {
   /*
    * Because Windows uses a case-insensitive file system, operate on
    * a lowercase version of the given filename. Note: This ignores
    * globalization issues and assumes ASCII characters.
    */
	if (casecmp(path, reserved[i]) == 0) {
			returnValue = 1;
    }
  }
  return returnValue;
}

