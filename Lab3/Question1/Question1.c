#include <stdio.h>
int str_len(char s[]) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}
void str_concat(char s1[], char s2[]) {
    int i = str_len(s1), j = 0;
    while (s2[j] != '\0') s1[i++] = s2[j++];
    s1[i] = '\0';
}
int str_cmp(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]) i++;
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
void str_insert(char s[], char sub[], int pos) {
    int len = str_len(s), sublen = str_len(sub);
    for (int i = len - 1; i >= pos; i--) s[i + sublen] = s[i];
    for (int i = 0; i < sublen; i++) s[pos + i] = sub[i];
    s[len + sublen] = '\0';
}
int find(char *s, char *sub) {
    int ls = str_len(s), lsub = str_len(sub);
    for (int i = 0; i <= ls - lsub; i++) {
        int j = 0;
        while (j < lsub && s[i+j] == sub[j]) j++;
        if (j == lsub) return i;
    }
    return -1;
}
void str_del(char s[], int pos, int len) {
    int i = pos;
    while (s[i + len] != '\0') {s[i] = s[i + len], i++;}
    s[i] = '\0';
}
int main() {
    char s[100], t[100], sub[100];
    int pos, del_len;

    printf("s: "); scanf(" %[^\n]", s);
    printf("t: "); scanf(" %[^\n]", t);
    printf("sub: "); scanf(" %[^\n]", sub);

    printf("Len s=%d\n", str_len(s));
    str_concat(s, t);
    printf("Concat: %s\n", s);
    printf("Cmp s, t=%d\n", str_cmp(s, t));

    printf("Insert pos: "); scanf("%d", &pos);
    str_insert(s, sub, pos);
    printf("After insert: %s\n", s);

    pos = find(s, sub);
    if (pos >= 0) {
        del_len = str_len(sub);
        str_del(s, pos, del_len);
        printf("After delete: %s\n", s);
    } else printf("Sub not found\n");

    return 0;
}
