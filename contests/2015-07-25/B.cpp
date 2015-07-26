#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
const int Mn = 100;
char s[Mn][Mn];
inline int get_weight(int val) {
	int res(0);
	while(val) {
		if(val & 1)
			res += 500;
		else
			res += 250;
		val >>= 1;
	}
	return res;
}
inline int cmp(int x, int y) {
	return x < y ? -1 : x > y;
}
inline int find_pos(int l, int r) {
	for(int i = 0; i < 8; ++i)  {
		for(int j = l; j < r; ++j)
			if(s[i][j] != '.')
				return i;
	}
}
inline void print(int row, int l ,int r) {
	for(int i = l; i < r; ++i)
		printf("%c", s[row][i]);
}
int main() {
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; ++cas) {

		for(int i = 0; i < 8; ++i) {
			scanf("%s", s[i]);
		}
		//for(int i = 0; i < 8; ++i)
		//	puts(s[i]);
		int left_weight(0);
		int right_weight(0);
		int left_pos(find_pos(0, 8));
		int right_pos(find_pos(10, 18));

		for(int i = 0; i < 8; ++i) {
			bool flag(false);
			for(int j = 0; s[i][j]; ++j) {
				if(s[i][j] == '|')
					flag = true;
				if(s[i][j] >= 'A' && s[i][j] <= 'Z') {
					if(!flag)
						left_weight += get_weight(s[i][j]);
					else 
						right_weight += get_weight(s[i][j]);
				}
			}
		}

//cerr << left_pos << "vs" << right_pos << "--" << left_weight << "vs" << right_weight << endl;
		
		printf("Case %d:\n", cas);
		if(cmp(left_weight, right_weight) == cmp(left_pos, right_pos)) {
			printf("The figure is correct.\n");
		} else {
			if(cmp(left_weight, right_weight) == -1) {
				for(int i = 0; i < 2; ++i) {
					print(left_pos + i, 0, 8);
					printf("||");
					printf("........");
					printf("\n");
				}
				for(int i = 2; i < 5; ++i) {
					print(left_pos + i, 0, 8);
					printf("||");
					print(right_pos + i - 2, 10, 18);
					printf("\n");
				}
				for(int i = 5; i < 7; ++i) {
					printf("........");
					printf("||");
					print(right_pos + i - 2, 10, 18);
					printf("\n");
				}
 			} else if(cmp(left_weight, right_weight) == 0) {
 				printf("........||........\n");
 				for(int i = 0; i < 5; ++i) {
 					print(left_pos + i, 0, 8);
 					printf("||");
 					print(right_pos + i, 10, 18);
 					printf("\n");
 				}
 				printf("........||........\n");
			} else {
				for(int i = 0; i < 2; ++i) {
					printf("........");
					printf("||");
					print(right_pos + i, 10, 18);
					printf("\n");
				}
				for(int i = 2; i < 5; ++i) {
					print(left_pos + i - 2, 0, 8);
					printf("||");
					print(right_pos + i, 10, 18);
					printf("\n");
				}
				for(int i = 5; i < 7; ++i) {
					print(left_pos + i - 2, 0, 8);
					printf("||");
					printf("........");
					printf("\n");
				}
			}
  		}
	}
	return 0;
}