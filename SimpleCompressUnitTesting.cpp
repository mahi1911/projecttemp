#include"stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int simple_compress(unsigned char *data_ptr, int data_size);

/*

This function will be called with two arguments; a pointer to the data buffer (data_ptr) and the number of bytes to compress (data_size).
After the function executes the data in the buffer will be modified and the size of the modified buffer will be returned.

The data_ptr will point to an array of bytes.  Each byte will contain a number from 0 to 127 (0x00 to 0x7F).

The function will replace a sequence of a value repeated two or more times with a marker that indicates a repeated value and the number of times it is repeated.
The marker in the data will have bit 7 set (0x80).  The remaining seven bits of the byte are used to indicate the number of times the value repeats (ie: 0x91, repeats 0x11 or 17 times).
The next byte following the marker will be the repeated data (ie: 0x87 0x34; 0x34 was repeated 7 times).

*/

int main()
{
	/* Arrange */
	//unsigned char var[] = { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4, 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4}; //Number sequence repeated morethan 127 times
	unsigned char var[] = { 'a', 'b', 'c' };
	//unsigned char var[] = { 'a1', 'a2', 'c3' };

	ifstream testData;
	testData.open("example.txt");

	/*int src_data_size = sizeof(var);
	cout << "Data size before compression: " << src_data_size << endl;
	cout << "Data before compression:" << endl;
	for (auto i : var)
		cout << (int)i << " ";
	cout << endl;	*/

	/* Act*/
	int dst_size = simple_compress(var, sizeof(var));

	cout << "Compressed data size: "<< dst_size << endl;
	cout << "Data after compression:" << endl;
	for (int i=0;i<dst_size;i++)
		cout << (int)var[i] << " ";

	cout << endl;

	/* Asserts*/

	return 0;
}

int simple_compress(unsigned char *data_ptr, int data_size)
{
	int   src_idx = 0;
	int   dst_idx = 0;
	unsigned char next_byte;

	while (src_idx < (data_size - 1))
	{
		next_byte = data_ptr[src_idx + 1];

		if (data_ptr[src_idx] == next_byte)
		{
			data_ptr[dst_idx] = 0x81;

			while ((data_ptr[++src_idx] == next_byte)
				&& (src_idx < data_size))
			{
				data_ptr[dst_idx]++;
			}

			data_ptr[++dst_idx] = next_byte;
			dst_idx++;
		}
		else
		{
			data_ptr[dst_idx++] = data_ptr[src_idx++];
		}
	}

	if (src_idx < data_size)
	{
		data_ptr[dst_idx++] = data_ptr[src_idx];
	}

	return dst_idx;
}

