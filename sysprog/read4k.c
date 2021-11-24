/**
 * int read(int length, char *buf);
 * length - input, number of bytes to read
 * buf - buffer sufficient to hold number of requested bytes
 * returns - number of bytes read
 * calls - read4k()
**/

/**
 * int read4k(char *buf);
 * buf - input buffer to read the bytes
 * returns - number of bytes read. may read from a file or network stream
 * it is possible it can return less number of bytes for whetever reason.
 * The function returns -1 when EOF is reached.
 **/

int read4k(char *buf);

#define 4K 4096

char g_buf[4K] = {0};
int g_bufp = -1; 

int read(int length, char *buf) {
	// length <= 0, return
	// always return from the local buffer
	// if there are enough bytes in the local buffer, return
	// if there are not enough bytes in the local buffer, invoke read4k()
	// if enough data is read, save in the local buffer and return from local buffer
	// while reading EOF reached, return the local buffer
	// if 0 bytes read, keep reading
	int count = 0;
	int remaining = length;
	bufp = 0;
	int read = 0;

	if (length <= 0) {
		printf("invalid read length\n");
		return 0;
	}

	while (remaining > 0) {
		// if flag is -1, then read the stream
		if (g_bufp == -1) {
			read = read4k(g_buf);
			if (read <= 0) {
				// typically not an error case, could be an
				// issue with input stream. but for now, break
				break;
			}

			if (read >= remaining) {
				// enough data is read from the stream, copy
				// to buf and return the count
				memcpy(buf + bufp, g_buf + bufp, remaining);
				count += remaining;
				g_bufp += remaining; // current location of global buffer
				return count;
			} else {
				// data read from the stream is less than requested
				remaining = remaining - read;
				count = count + read;
				g_bufp = -1; // not enough data read, read again
				memcpy(buf + bufp, g_bufp + bufp, read);
				bufp = bufp + read;
				// go back and read from the stream again
			}
		} else  {
			// okay looks like internal buffer has some data
			// let us copt that first and go back to read if
			// needed
			if (4K - g_bufp > remaining) {
				// okay, so the internal buffer has enough data
				// let us copy and return
				memcpy(buf + bufp, g_bufp + g_bufp, remaining);
				g_bufp += remaining;
				count += remaining;
				bufp += remaining;
				return count;
			} else {
				// we have some data but not sufficient
				// let us copy whatever we have and then go
				// read the stream again
				memcpy(buf + bufp, g_bufp + g_bufp, 4K - g_bufp);
				count += 4K - g_bufp;
				bufp += 4K - g_bufp;
				remaining -= 4K - g_bufp;
				g_bufp = -1;
			}
		}
	}

	return count;
}

