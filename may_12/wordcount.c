#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Word {
	char* data;
	size_t count;
};

typedef struct Word Word;

Word create_word(char* param) {
 	Word word;
	word.data = (char*)malloc(strlen(param) + 1);
	strcpy(word.data, param);

	word.count = 1;

	return word;
}

struct WordList {
	Word* words;
	size_t size;
	size_t capacity;
};

typedef struct WordList WordList;

void add_word(WordList* wl, char* w) {
	if (w[strlen(w)-1] == '\n') 
		w[strlen(w)-1] = '\0';

	for (int i = 0; i < wl->size; ++i) {
		if (strcmp(wl->words[i].data, w) == 0) {
			++wl->words[i].count; // already present, just increase the counter
			return;
		}
	}

	if (wl->capacity == wl->size) { // check if we have enough space
		wl->capacity *= 2;
		wl->words = (Word*)realloc(wl->words, wl->capacity * sizeof(Word));
	}

	wl->words[wl->size++] = create_word(w); // add new word
}

int main() {
	WordList wl;
	wl.size = 0;
	wl.capacity = 8;
	wl.words = (Word*)malloc(wl.capacity * sizeof(Word));

	FILE* f = fopen("input.txt", "r");
	if (!f) {
		printf("error opening the file\n");
		return 1;
	}

	size_t read;
	ssize_t buffer;
	char* line;
	char* token;

	read = getline(&line, &buffer, f);
	while(read != -1) {
		token = strtok(line, " \n");
		while (token) {
			add_word(&wl, token);
			token = strtok(NULL, " \n");
		}
		//add_word(&wl, line);
		read = getline(&line, &buffer, f);
	}

	for (int i = 0; i < wl.size; ++i) {
		printf("%s: %ld\n", wl.words[i].data, wl.words[i].count);
	}

	return 0;
}
