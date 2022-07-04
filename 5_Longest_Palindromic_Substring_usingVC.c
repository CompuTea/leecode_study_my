// Longest_Palindromic_Substring.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DP_SIZE 1000
bool dp[DP_SIZE][DP_SIZE]={0};

void show_DP()
{
	/*printf("\n-----\n");
	int i, j;
	for(i=0; i<13; i++) {
		printf("\n");
		for (j=0; j<13; j++) {
			printf(" %d", dp[i][j]);
		}
	}*/
}

char ans[DP_SIZE];
char* longestPalindrome(char* s)
{
	printf("\n longestPalindrome: %s", s);

	int s_len;
	int i, j;
	int start, end, len_max, len;
	
	len_max=0;
	len=0;
	start=0;
	end=0;
	s_len = strlen(s);

	for(i=0; i<s_len; i++) {
		dp[i][i]=1;

		start=i;
		end=i;
		if((end-start) > len_max) {
			len_max = (end-start);
		}
	}
	// show_DP();

	for(i=0; i<(s_len-1); i++) {
		if(s[i] == s[i+1]) {
			dp[i][i+1]=1;

			start=i;
			end=(i+1);
			if((end-start) > len_max) {
				len_max = (end-start);
			}
		}
		
	}	
	// show_DP();
	
	i=0;
	j=2;
	int loop=2;
	while((j-i)<s_len) {
		if(j>=s_len) {
			i=0;
			loop++;
			j=loop;
		}

		if((s[i] == s[j]) && (dp[i+1][j-1] == 1)) {
			dp[i][j]=1;
			
			// show_DP();
			
			if((j-i+1) > len_max) {
				start=i;
				end=j;
				len_max = (end-start+1);
			}

		}

		i++;
		j++;
	}

	// show_DP();
	
	memcpy(ans, s+start, (end-start+1));	
	ans[(end-start)+1]='\0';
	printf("\nANS => %s", ans);

	return ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char* input;
	input="aacabdkacaa";

	printf("\n %s", longestPalindrome(input));

	system("pause");
	return 0;
}
