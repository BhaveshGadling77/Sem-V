#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdbool.h>
#define SIZE 2048

bool findPattern(char *line, char *word, int wordLen, int lineLen) {
	int j = 0;
	if (wordLen == 0)
		return true;
	
	for (int i = 0; i <= lineLen - wordLen; i++) {
		j = 0;
		for (j = 0; j < wordLen; j++) {
			if (line[i + j] != word[j]) 
				break;
		}
		if (j == wordLen) {
			return true;
		}
	}
	return false;
}

int readline(int fd, char *buffer) {
	int i = 0;
	char ch;
	while (i < SIZE && read(fd, &ch, 1) == 1) {
		buffer[i++] = ch;
		if (ch == '\n') {
			break;
		}
	}
	buffer[i] = '\0';
	return i;
}
void solve (char *filename, char *word) {
	
	int wordLength = strlen(word);
	int fd = open(filename, O_RDONLY);
	if (fd == -1) {
		write(2, "Cannot open file\n", 17);
		return;
	}
	char line[SIZE];
	int sizeRead = 0;
	while ((sizeRead = readline(fd, line))) {
		// write(1, line, sizeRead); //debug
		// write(1, "\n-----\n", 7); //debug
		if (findPattern(line, word, wordLength, sizeRead)) {
			write(1, line, sizeRead);
		}
	}

	close(fd);
}
int main (int argc, char *argv[]) {
	/* Expected argv[1] -> input file.
	 * Expected argv[2] -> word specified.
	 * mis conceptions: 
	 * - you do not need to tokenise the input file lines.
	 */
	if (argc != 3) {
		write(2, "Usage: ./a.out <file> <word>\n", 29);
		return 1;
	}

	/* read the line by line 
	 **/
	solve(argv[1], argv[2]);
	
	return 0;
}
