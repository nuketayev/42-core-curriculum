#include "../../inc/push_swap.h"

static int count_words(char *s, char c) {
	int count;
	bool inside_word;

	count = 0;
	while (*s) {
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s) {
			if (!inside_word) {
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char *get_next_word(char *s, char c) {
	static int cursor = 0;
	char *next_word;
	int len;
	int i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (i < len) {
		next_word[i] = s[cursor + i];
		++i;
	}
	next_word[i] = '\0';
	cursor += len;
	return (next_word);
}

void free_words(char **words, int count) {
	for (int i = 0; i < count; ++i) {
		free(words[i]);
	}
	free(words);
}

char **split(char *s, char c) {
	int word_count = count_words(s, c);
	char **words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	for (int i = 0; i < word_count; ++i) {
		words[i] = get_next_word(s, c);
		if (!words[i]) {
			free_words(words, i);
			return (NULL);
		}
	}
	words[word_count] = NULL;
	return (words);
}
