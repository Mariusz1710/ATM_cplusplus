#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "clear_buf.h"

void clear_buf()
{
	cin.clear();
	cin.ignore(1000, '\n');
	cin.get();
}